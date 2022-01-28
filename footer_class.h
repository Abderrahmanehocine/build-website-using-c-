#include "header_files.h"

namespace footerCode {
  class footer{
    private: 
     string htmlCode;
     string cssCode;
     int footerNumber;
    public:
      void chooseFooter(string webSiteName){
         cout<<"Footer 1:\n"
               "--------------------------------------\n"
               "| (Website Name) all rights reserved |\n"
               "--------------------------------------\n"
               "Footer 2:\n"
               "--------------------------------------\n"
               "| (footer background color)          |\n"
               "| (Website Name) all rights reserved |\n"
               "--------------------------------------\n";  
               cout<<"Enter footer number: ";
               cin>>footerNumber;        
               generateCode(webSiteName);
      }
      void generateCode(string webSiteName){
        htmlCode="  <footer>\n   <div class=\"footerdiv\">";
        htmlCode+= webSiteName;
        htmlCode+= " all rights reserved\n";
        htmlCode+= "   </div>\n";
        htmlCode+= "  </footer>\n";
        cssCode+= "footer{\n";
        cssCode+= " margin-left: auto;\n margin-right: auto;\n}\n";
        cssCode+= "div.footerdiv{\n";
        cssCode+= " position: fixed;\n";
        cssCode+= " left: 0;\n bottom: 0;\n";
        cssCode+= " width: 100%;\n";
        cssCode+= " text-align: center;\n";
        if(footerNumber == 2){
            string footerBackgroundColor;
            cout<<"Footer Background Color: " ;
            cin>>footerBackgroundColor;
            cssCode+= " background-color: "+footerBackgroundColor+";\n";
            string footerTextColor;
            cout<<"Footer text color: ";
            cin>>footerTextColor;
            cssCode+=" color: "+footerTextColor+";\n";
        }
        cssCode+= "}\n";
      }
     string getHtmlCode() { 
         return htmlCode; 
        }
     string getCssCode() { 
         return cssCode;
     }
  };
}