#include "header_files.h"

    class Page{
      private:
       string htmlCode;
       string cssCode;
       string videoLink;
       string text;
       int chooseNumber;
      public:
       void choosePage(string headerHtml , string footerHtml , string pageName , string backgroundColor){
          cout<<"Page 1:\n"
                "--------------------------------------\n"
                "|  youtube Video  |   youtube Video   |\n"
                "--------------------------------------\n"
                "Page 2:\n"
                "--------------------------------------\n"
                "|  youtube Video  |       Text        |\n"
                "--------------------------------------\n";
           cout<<"Enter page number: ";
           cin>>chooseNumber;
           generateCode(headerHtml,footerHtml,pageName,backgroundColor);
       }
       void generateCode(string headerHtml , string footerHtml , string pageName , string backgroundColor){
         htmlCode= "<html>\n";
         htmlCode+= " <head>\n";
         htmlCode+= "  <title>\n";
         htmlCode+= pageName+"  \n</title>\n";
         htmlCode+= "  <link rel=\"stylesheet\" href=\"css\\header.css\">";
         htmlCode+= "  <link rel=\"stylesheet\" href=\"css\\footer.css\">";
          cssCode= "body{\n";
         cssCode+= " background-color: "+backgroundColor+";\n}";
         cssCode+= " table.pageTable{\n";
         cssCode+= "   margin-right: auto;\n  margin-left: auto;\n";
         cssCode+= "  width: 80%;\n}";
         cssCode+= " td.pageTd{\n";
         cssCode+= "  color: white;\n  text-align: center;\n}\n ";
         cssCode+= " iframe{\n";
         cssCode+= "  width: 100%;\n}\n";
         htmlCode+= "  <style>\n"+cssCode+"\n</style>\n";
         htmlCode+= " </head>\n";
         htmlCode+= " <body>\n";
         htmlCode+= "  <br>\n"+headerHtml+"\n  <br><br>\n";
         htmlCode+= "  <table class=\"pageTable\">\n";
         addRow:
         htmlCode+= "    <tr>\n";
         htmlCode+= "     <td class=\"pageTd\">\n";
         cout<<"Enter video Link: ";
         cin>>videoLink;
         htmlCode+= "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/"
                    +videoLink+
                    "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen>\n"
                    "  </iframe>";
         htmlCode+= "     </td>\n";
         if(chooseNumber == 1){
             htmlCode+= "     <td class=\"pageTd\">\n";
             cout<<"\nEnter video Link: ";
             cin>>videoLink;
             htmlCode+= "<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/"
                        +videoLink+
                        "\" title=\"YouTube video player\" frameborder=\"0\" allow=\"accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen>\n"
                        "  </iframe>";
             htmlCode+= "     </td>\n";
         }
         else if(chooseNumber == 2){
             cout<<"\nEnter the text: ";
             scanf("\n");
             getline(cin,text);
             htmlCode+= "     <td class=\"pageTd\">\n";
             htmlCode+= text+"\n";
         }
         cout<<"\nDo you want to add row[y/n]: ";
         cin>>text;
         if(text == "y"){
             goto addRow;
         }
         htmlCode+="     </tr>\n";
         htmlCode+= footerHtml+"\n";
         htmlCode+= " </body>\n";
         htmlCode+= "</html>\n";
       }
       string getHtml(){
           return htmlCode;
       }
    };
