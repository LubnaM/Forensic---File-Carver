#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <string>
#include <stdio.h>
using namespace std;
string MPGFNCount="1";
string GIFFNCount="1";
string PDFFNCount="1";
string JPGFNCount="1";
string ARTFNCount="1";
string DOCXFNCount="1";
string RTFFNCount="1";
string PNGFNCount="1";
void gif(long&CurrentPosition , ifstream& myfile);
void mpg(long& CurrentPosition , ifstream & myfile);
void pdf(long&CurrentPosition , ifstream& myfile);
void png(long&CurrentPosition , ifstream& myfile);
void docx(long&CurrentPosition , ifstream& myfile);
void rtf(long&CurrentPosition , ifstream& myfile);
void art(long&CurrentPosition , ifstream& myfile);
void jpg(long&CurrentPosition , ifstream& myfile);
int main ()
{
 int i;
 long CurrentPosition,cp1,FileSize , FPP,count=0;
string line;
ifstream myfile;
mkdir("c:/File Carver");
mkdir("c:/File Carver/MPEG Files");
mkdir("c:/File Carver/GIF Files");
 mkdir("c:/File Carver/DOCX Files");
 mkdir("c:/File Carver/JPG Files");
 mkdir("c:/File Carver/ART Files");
 mkdir("c:/File Carver/PNG Files");
 mkdir("c:/File Carver/RTF Files");
 mkdir("c:/File Carver/PDF Files");
char path[260],ch,ch_cmp[9],gif_h1[]={0x47,0x49,0x46,0x38,0x37,0x61
},pdf_h[]={0x25,0x50,0x44,0x46},
 gif_h2[]={0x47,0x49,0x46,0x38,0x39,0x61
},png_h[]={0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A},
 docs_h[]={0x50,0x4B,0x03,0x04,0x14,0x00,0x06,0x00},rtf_h[]={0x7B,0x5C,0x72,0x74,0x66,0x31},

mpg_h[]={0x00,0x00,0x01,0xBA},art_h1[]={0x4A,0x47,0x03,0x0E},art_h2[]={0x4A,0x47,0x04,0x0E},
 jpg_h[]={0xFF,0xD8,0xFF,0xE0,'x','x', 0x4A, 0x46, 0x49, 0x46, 0x00};


cout <<"Please Enter the image location path.."<<endl;
//Ask the end user for the raw data file location path , ex: C:/raw.dd
cin.getline(path,260);

//Will read the path that is entered by the end user and save it to string variable "path"
myfile.open(path,ios::binary|ios::in); // This part of code will
if(myfile.is_open()) // check if the file exist
{ // and can it be opened or not !


 myfile.seekg(0,ios::beg);
 myfile.get(ch);
 while(!myfile.eof())
 {

 for(i=0;(i<10 && !myfile.eof());i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;
 int j=0;
 
 if (ch_cmp[j]==jpg_h[j] && ch_cmp[j+1]==jpg_h[j+1] && ch_cmp[j+2]==jpg_h[j+2] && (
ch_cmp[j+3]==jpg_h[j+3] ||ch_cmp[j+3]=='�'||ch_cmp[j+3]=='�')&& ch_cmp[j+6]==jpg_h[j+6]&&
ch_cmp[j+7]==jpg_h[j+7] && ch_cmp[j+8]==jpg_h[j+8])
 {
FPP=myfile.tellg();
 CurrentPosition=FPP-11;//myfile.seekg(512,ios::cur);
 jpg (CurrentPosition,myfile);
 }

 else
 {
 myfile.seekg(-10,ios::cur);
 }
 myfile.get(ch);
 }

myfile.close() ;
cout <<endl<<endl<<"Check C:/File Carver to see the carved files .. " << endl << endl;
}
 else
cout<<" The file could not be opened .. ! \n";
system ("Pause");
 return 0 ;
}
void mpg(long&CurrentPosition , ifstream& myfile)
{
 int i;
 ofstream outfile;
string Fname;
 long position ,last_position=0 ,size ;
 bool exists=false;
 char mpg_t[]={0x00,0x00,0x01,0xB9},ch,ch_cmp[4];
 myfile.get(ch);
 while(!myfile.eof() && exists!=true)
 {
 for(i=0;(i<3 && (!myfile.eof()));i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;
 int j=0;
 if(ch_cmp[j]==mpg_t[j] && ch_cmp[j+1]==mpg_t[j+1] &&
 ch_cmp[j+2]==mpg_t[j+2] && (ch_cmp[j+3]==mpg_t[j+3]))
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 { position = myfile.tellg();
 position-=3;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
}
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 if(exists==true){
 Fname="c:/File Carver/MPEG Files/MPEG_"+MPGFNCount+".mpeg";
outfile.open(Fname.c_str(),ios::binary|ios::out);
 for(int k=0 ; k<size;k++)
 {
 myfile.get(ch);
 outfile<<ch;
 }
 MPGFNCount+="1";}
 CurrentPosition=myfile.tellg();

}
void gif(long&CurrentPosition , ifstream& myfile)
{
 int i;
 ofstream outfile;
 string Fname;
 long position ,last_position=0 ,size ;
 bool exists=false;
 char gif_t[]={0x00,0x3B,0x00},ch,ch_cmp[3];
 myfile.get(ch);
while(!myfile.eof() && exists!=true)
 {
 for(i=0;(i<2 && (!myfile.eof()));i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;
 int j=0;
 if(ch_cmp[j]==gif_t[j] && ch_cmp[j+1]==gif_t[j+1]&& ch_cmp[j+2]==gif_t[j+2])
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 { position = myfile.tellg();
 position-=2;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
 }
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 if(exists==true){
Fname="c:/File Carver/GIF Files/GIF_"+GIFFNCount+".gif";
outfile.open(Fname.c_str(),ios::binary|ios::out);
 for(int k=0 ; k<size;k++)
 {
 myfile.get(ch);
 outfile<<ch;
 }
 GIFFNCount+="1";}
 CurrentPosition=myfile.tellg();
 }
void pdf(long&CurrentPosition , ifstream& myfile)
{
 int i;
 ofstream outfile;
 string Fname;
 long position ,last_position=0,size ;
 bool exists=false;
 char pdf_t1[]={0x25,0x25,0x45,0x4F,0x46,0x0A },
 
 ch,ch_cmp[6];
 myfile.get(ch);
 while(!myfile.eof() && exists!=true)
 {
for(i=0;(i<5 && !myfile.eof());i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;
 int j=0;
 if(ch_cmp[j]==pdf_t1[j] && ch_cmp[j+1]==pdf_t1[j+1] && ch_cmp[j+2]==pdf_t1[j+2] &&
ch_cmp[j+3]==pdf_t1[j+3] && ch_cmp[j+4]==pdf_t1[j+4]&& ch_cmp[j+5]==pdf_t1[j+5])
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 {
 position = myfile.tellg();
 position-=5;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
 }
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 if(exists==true){
 Fname="c:/File Carver/PDF Files/PDF_"+PDFFNCount+".pdf";
outfile.open(Fname.c_str(),ios::binary|ios::out);
 for(int k=0 ; k<size;k++)
 {
 myfile.get(ch);
 outfile<<ch;
 }
 PDFFNCount+="1";}
 CurrentPosition=myfile.tellg();
}
void png(long&CurrentPosition , ifstream& myfile)
{
 int i;
 ofstream outfile;
 string Fname;
 long position ,last_position=0 ,size ;
 bool exists=false;
 char png_t[]={0x49,0x45,0x4E,0x44,0xAE,0x42,0x60,0x82},ch,ch_cmp[8];
 myfile.get(ch);
 while(!myfile.eof() && exists!=true)
 {
 for(i=0;(i<7 && (!myfile.eof()));i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }

 ch_cmp[i]=ch;
 int j=0;
 if(ch_cmp[j]==png_t[j] && ch_cmp[j+1]==png_t[j+1]&&ch_cmp[j+2]==png_t[j+2] &&
ch_cmp[j+3]==png_t[j+3]&&ch_cmp[j+4]==png_t[j+4] &&
ch_cmp[j+5]==png_t[j+5]&&ch_cmp[j+6]==png_t[j+6] && ch_cmp[j+7]==png_t[j+7])
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 { position = myfile.tellg();
 position-=7;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
 }
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 if(exists==true){
 Fname="c:/File Carver/PNG Files/PNG_"+PNGFNCount+".png";
outfile.open(Fname.c_str(),ios::binary|ios::out);
 for(int k=0 ; k<size;k++)
 {
 myfile.get(ch);
 outfile<<ch;

 }
 PNGFNCount+="1";}
 CurrentPosition=myfile.tellg();

}
void docx(long&CurrentPosition , ifstream& myfile)
{
 int i,l,c,count=0,num=0;
 ofstream outfile;
 string Fname,cfn;
 long position ,last_position=0 ,size ;
 bool exists=false;
 char docs_t[]={0x50,0x4B,0x05,0x06
},ch,ch_cmp[4],f1[]={'c',':','/','e','x','a','m','p','l','e','.','t','x','t'},f2[]={'c',':','/','e','.','t','x','t'},cmp[8],
 word[]={'w','o','r','d','/','d','o','c'},
 excel[]={'x','l','/','w','o','r','k','s'},ppt[]={'p','p','t','/','s','l','i','d'};
 myfile.get(ch);
 while(!myfile.eof() && exists!=true)
 {
 for(i=0;(i<3 && (!myfile.eof()));i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;
 int j=0;

 if(ch_cmp[j]==docs_t[j] && ch_cmp[j+1]==docs_t[j+1]&&ch_cmp[j+2]==docs_t[j+2] &&
ch_cmp[j+3]==docs_t[j+3])
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 { position = myfile.tellg();
 position-=3;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
 }
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 i=0;
 while (exists==true && i<size && num==0)
 {
 for(int l=0 ; l<8;l++)

 {
 myfile.get(ch);
 cmp[l]=ch;
 count++;

 }

 c=0;
 if(cmp[c]==word[c] && cmp[c+1]==word[c+1] && cmp[c+2]==word[c+2] &&
cmp[c+3]==word[c+3] && cmp[c+4]==word[c+4] && cmp[c+5]==word[c+5] &&
cmp[c+6]==word[c+6] && cmp[c+7]==word[c+7])
 num=1;
 else
 if(cmp[c]==excel[c] && cmp[c+1]==excel[c+1] && cmp[c+2]==excel[c+2] &&
cmp[c+3]==excel[c+3] && cmp[c+4]==excel[c+4] && cmp[c+5]==excel[c+5] &&
cmp[c+6]==excel[c+6] && cmp[c+7]==excel[c+7])
 num=2;
 else
 if(cmp[c]==ppt[c] && cmp[c+1]==ppt[c+1] && cmp[c+2]==ppt[c+2] && cmp[c+3]==ppt[c+3] &&
cmp[c+4]==ppt[c+4] && cmp[c+5]==ppt[c+5] && cmp[c+6]==ppt[c+6] && cmp[c+7]==ppt[c+7])
 num=3;
 }

 if (num==1)
 {Fname="c:/File Carver/DOCX Files/DOCX_"+DOCXFNCount+".docx";}
 else
 if (num==2)
 {Fname="c:/File Carver/DOCX Files/XLSX_"+DOCXFNCount+".xlsx";}
 else
 if (num==3)
 {Fname="c:/File Carver/DOCX Files/PPTX_"+DOCXFNCount+".pptx";}
 if(exists==true){
 outfile.open(Fname.c_str(),ios::binary|ios::out);
 myfile.seekg(-count,ios::cur);
 for(int k=0 ; k<(size+18);k++)

 {
 myfile.get(ch);
 outfile<<ch;
 }
 DOCXFNCount+="1";}
 CurrentPosition=myfile.tellg();

}
void rtf(long&CurrentPosition , ifstream& myfile)
{
 int i;
 ofstream outfile;
 string Fname;
 long position ,last_position=0 ,size ;
 bool exists=false;
 char rtf_t[]={0x5C,0x70,0x61,0x72,0x20,0x7D,0x7D,0x0A},ch,ch_cmp[8];
 myfile.get(ch);
 while(!myfile.eof() && exists!=true)
 {
 for(i=0;(i<7 && (!myfile.eof()));i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;

 int j=0;
 if(ch_cmp[j]==rtf_t[j] && ch_cmp[j+1]==rtf_t[j+1]&&ch_cmp[j+2]==rtf_t[j+2] &&
ch_cmp[j+3]==rtf_t[j+3]&& ch_cmp[j+4]==rtf_t[j+4]&& ch_cmp[j+5]==rtf_t[j+5]&&
ch_cmp[j+6]==rtf_t[j+6]&& ch_cmp[j+7]==rtf_t[j+7])
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 { position = myfile.tellg();
 position-=7;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
 }
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 if(exists==true){
 Fname="c:/File Carver/RTF Files/RTF_"+RTFFNCount+".rtf";
outfile.open(Fname.c_str(),ios::binary|ios::out);
 for(int k=0 ; k<size;k++)
 {
 myfile.get(ch);
 outfile<<ch;
 }

 RTFFNCount+="1";}
 CurrentPosition=myfile.tellg();
}
void art(long&CurrentPosition , ifstream& myfile)
{
 int i;
 ofstream outfile;
 string Fname;
 long position ,last_position=0 ,size ;
 bool exists=false;
 char art_t1[]={0xD0,0xCB,0x00,0x00},art_t2[]={0xCF,0xC7,0xCB},ch,ch_cmp[4];
 myfile.get(ch);
 while(!myfile.eof() && exists!=true)
 {
 for(i=0;(i<3 && (!myfile.eof()));i++)
 {

 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;
 int j=0;
 if((ch_cmp[j]==art_t1[j] ||ch_cmp[j]==art_t2[j]) && (ch_cmp[j+1]==art_t1[j+1]
||ch_cmp[j+1]==art_t2[j]+1) && (ch_cmp[j+2]==art_t1[j+2] ||ch_cmp[j+2]==art_t2[j+2])
||ch_cmp[j+3]==art_t1[j+3])
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 { position = myfile.tellg();
 position-=3;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
 }
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 if(exists==true){
 Fname="c:/File Carver/ART Files/ART_"+ARTFNCount+".art";
outfile.open(Fname.c_str(),ios::binary|ios::out);
 for(int k=0 ; k<size;k++)
 {
 myfile.get(ch);
 outfile<<ch;
 }
 ARTFNCount+="1";}
 CurrentPosition=myfile.tellg();

}
void jpg(long&CurrentPosition , ifstream& myfile)

{
 int i;
 ofstream outfile;
 string Fname;
 long position ,last_position=0 ,size ;
 bool exists=false;
 char jpg_t[]={0xFF,0xD9},ch,ch_cmp[2];
 myfile.get(ch);
 while(!myfile.eof() && exists!=true)
 {
 for(i=0;(i<1 && (!myfile.eof()));i++)
 {
 ch_cmp[i]=ch;
 myfile.get(ch);
 }
 ch_cmp[i]=ch;
 int j=0;
 if(ch_cmp[j]==jpg_t[j] && ch_cmp[j+1]==jpg_t[j+1])
 {
 position=myfile.tellg();
 exists=true;
 }
 else
 { position = myfile.tellg();
 position-=1;
 myfile.seekg(position,ios::beg);
 myfile.get(ch);
 }
 }
 size=position-CurrentPosition;
 myfile.seekg(-size,ios::cur);
 if(exists==true){
 Fname="c:/File Carver/JPG Files/JPG_"+JPGFNCount+".jpg";
outfile.open(Fname.c_str(),ios::binary|ios::out);
 for(int k=0 ; k<size;k++)
 {
 myfile.get(ch);
 outfile<<ch;
 }
 JPGFNCount+="1";}
 CurrentPosition=myfile.tellg();
 cout<<"End Sector for JPEG is .. > " <<myfile.tellg()<< endl ;
}