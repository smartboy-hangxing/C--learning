#include <iostream>


// create a blank document.
System::SharedPtr<Document> doc = System::MakeObject<Document>();
// the DocumentBuilder class provides members to easily add content to a document.
System::SharedPtr<DocumentBuilder> builder = System::MakeObject<DocumentBuilder>(doc);
// write a new paragraph in the document with the text "Hello World!"
builder->Writeln(u"Hello World!");
// save the document. 
// the format to save as is inferred from the extension of the file name.
doc->Save(u"output.docx");
