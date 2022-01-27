#include "header_files.h"

namespace HeaderCode{
  class Header{
   private:
    string htmlCode;
    string cssCode;
    int headerChose;
    string intToString(int pageNameSize){
      if(pageNameSize == 1){
        return "1";
      }
      else if(pageNameSize == 2){
        return "2";
      }
      else if(pageNameSize == 3){
        return "3";
      }
      else if(pageNameSize == 4){
        return "4";
      }
      else if(pageNameSize == 5){
        return "5";
      }
      else if(pageNameSize == 6){
        return "6";
      }
      else if(pageNameSize == 7){
        return "7";
      }
      else if(pageNameSize == 8){
        return "8";
      }
      else if(pageNameSize == 9){
        return "9";
      }
      else if(pageNameSize == 10){
        return "10";
      }
      return "0";
    }
   public:
    void choseHeader( vector<string> pageName ){
      cout<<endl<<"Header 1:\n"
      "------------------------\n"
      "|        Picture       |\n"
      "------------------------\n"
      "| Search | Home | Cart |\n"
      "------------------------\n"
      "\nHeader 2:\n"
      "------------------------\n"
      "| Search | Home | Cart |\n"
      "------------------------\n";
      cout<<"\nEnter number of header: ";
      cin>>headerChose;
      generateCode(pageName);
    }
    void generateCode( vector<string> pageName ){
      htmlCode="  <table class=\"headertable\">\n";
      if(headerChose == 1){
        string pictureFileName;
        cout<<"Enter picture file name: ";
        cin>>pictureFileName;
        htmlCode+="   <tr>\n    <td class=\"headertd\" colspan=\""+intToString(pageName.size())+"\">\n"   
        "     <img class=\"headerimg\" src=\""+pictureFileName+"\"/>\n";
        htmlCode+="    </td>\n   </tr>\n";
      }
      htmlCode+="   <tr>\n";
      htmlCode+="    <td class=\"headertd\">\n<a class=\"headera\" href=\"""index.html\">\n"+pageName[0]+"\n    </td>\n";
      for(int i=1 ; i<pageName.size() ; i++){
        htmlCode+="    <td class=\"headertd\">\n<a class=\"headera\" href=\""+pageName[i]+".html\">\n"+pageName[i]+"\n    </td>\n";
      }
      htmlCode+="   </tr>\n  </table>";
      cssCode="table.headertable{\n";
      cssCode+="  width: 80%;\n";
      cssCode+="  margin-left: auto;\n  margin-right: auto;\n}\n";
      cssCode+="td.headertd{\n";
      cssCode+="  border: 1px solid white;\n";
      cssCode+="  color: white;\n  text-align: center;\n  font-size: 20px;\n}";
      cssCode+="a.headera{\n";
      cssCode+="  text-decoration: none;\n  color: white;\n";
      cssCode+="}\n";
      if(headerChose == 1){
        cssCode+="img.headerimg{\n";
        cssCode+="  width: 100px\n  heignt: auto\n}";
      }
    }
    string getHtml(){
      return htmlCode;
    }
    string getCss(){
      return cssCode;
    }
  };
}
