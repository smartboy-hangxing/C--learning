import os
import requests
from bs4 import BeautifulSoup
from openpyxl import Workbook


def download_images(keyword, num_images, min_size):
    # 创建保存图片的文件夹
    folder_path = keyword
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)

    # 创建Excel工作簿
    workbook = Workbook()
    sheet = workbook.active
    sheet.title = 'Image URLs'
    sheet.append(['Image URL'])

    search_engines = {
        # 'Google': f'https://www.google.com/search?q={keyword}&tbm=isch&hl=en&num={num_images}',
        # 'Bing': f'https://www.bing.com/images/search?q={keyword}&count={num_images}',
        # 'Yahoo': f'https://images.search.yahoo.com/search/images?p={keyword}&n={num_images}',
        'Baidu': f'https://image.baidu.com/search/flip?tn=baiduimage&word={keyword}&pn=0&rn={num_images}',
        # 'Yandex': f'https://yandex.com/images/search?text={keyword}&itype=jpg&isize=eq&iw={num_images}'
    }

    for search_engine, search_url in search_engines.items():
        response = requests.get(search_url)
        soup = BeautifulSoup(response.text, 'html.parser')
        images = soup.find_all('img')

        downloaded_count = 0

        for index, image in enumerate(images, 1):
            image_url = image['src']
            if not image_url.startswith('http'):  # 处理相对路径
                image_url = f"{search_url}/{image_url}"
            
            # 获取图片大小
            response = requests.head(image_url)
            size = int(response.headers.get("Content-Length", 0))
            if size < min_size:
                continue
            
            # 获取图片格式
            content_type = response.headers.get("Content-Type", "")
            if content_type not in ["image/jpeg", "image/png"]:
                continue

            image_filename = f"{keyword}_{search_engine}_{downloaded_count+1}.jpg"  # 图片文件名
            image_path = os.path.join(folder_path, image_filename)

            # 下载图片
            image_response = requests.get(image_url)
            with open(image_path, 'wb') as f:
                f.write(image_response.content)

            # 在Excel中添加图片URL
            sheet.append([image_url])

            downloaded_count += 1
            if downloaded_count == num_images:
                break

    # 保存Excel文件
    excel_path = os.path.join(folder_path, f"{keyword}_urls.xlsx")
    workbook.save(excel_path)

    print(f"共下载 {downloaded_count} 张大小不低于 {min_size / (1024)}KB 的主流图片（JPEG和PNG）到文件夹：{folder_path}")
    print(f"图片URL已保存在Excel文件：{excel_path}")


# 输入关键词和数量
keyword = input("请输入关键词：")
num_images = int(input("请输入要下载的图片数量："))

# 输入最小图片大小
min_size = 300 * 1024  # 300KB

# 调用函数进行图片下载和URL保存
download_images(keyword, num_images, min_size)
