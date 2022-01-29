#include "header_files.h"
#include "header_class.h"
#include "footer_class.h"
#include "page_class.h"

class webSite{
    private:
     string webSiteName;
     string backgroundColor;
     vector<string>pageName;
     string input;
     int numberOfPages;
    public:
     void creatWebSite(){
         cout<<"Enter website name: ";
         cin>>webSiteName;
         cout<<"Enter background color: ";
         cin>>backgroundColor;
         cout<<"Enter number of pages: ";
         cin>>numberOfPages;
         for(int i=0 ; i<numberOfPages ; i++){
            cout<<"Enter page"<<(i+1)<<" name: ";
            cin>>input;
            pageName.push_back(input);
         }
         Header h;
         h.chooseHeader(pageName);
         Footer f;
         f.chooseFooter(webSiteName);
         mkdir(webSiteName.c_str());
         string cssFolder = webSiteName;
         cssFolder+="//css";
         mkdir(cssFolder.c_str());
         string cssFile=cssFolder;
         cssFile+="//header.css";
         ofstream headerCssFile(cssFile);
         headerCssFile<<h.getCss();
         headerCssFile.close();
         cssFile=cssFolder;
         cssFile+="//footer.css";
         ofstream footerCssFile(cssFile);
         footerCssFile<<f.getCss();
         footerCssFile.close();
         for(int i=0 ; i<numberOfPages ; i++){
              Page p;
              cout<<pageName[i]<<" details"<<endl;
              p.choosePage(h.getHtml(),f.getHtml(),pageName[i],backgroundColor);
             string File=webSiteName;
             if(i==0){
                 File +="//index.html";
               }
             else{
                 File+="//"+pageName[i]+".html";       
               }
             ofstream pageHtml(File);
             pageHtml<<p.getHtml();
             pageHtml.close();
         }
     }
};