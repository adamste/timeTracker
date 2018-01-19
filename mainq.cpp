#include <iostream>
#include <windows.h>
#include <string>
#include <unistd.h>
#include <cstdlib>

using std::string;


string GetActiveWindowTitle();

int main(int argc, char** argv) {
	
	unsigned int wykopTime=0,facebookTime=0,rubbishTime=0,veryGoodJobTime=0,outlookTime=0,okTime=0,youtubeTime=0,afkTime=0;
	float wykopTimeInMinutes=0, facebookTimeInMinutes=0,rubbishTimeInMinutes=0,veryGoodJobTimeInMinutes=0,outlookTimeInMinutes=0,okTimeInMinutes=0,youtubeTimeInMinutes=0,afkTimeInMinutes=0;
	
	while(1){
	std::system("cls");
	
	string titleBar=GetActiveWindowTitle();
	std::cout<<titleBar<<std::endl;
	
	if(titleBar.find("Wykop")!= std::string::npos){
		wykopTime++;
		wykopTimeInMinutes=wykopTime/60;
	}else	
	
	if(titleBar.find("Facebook")!= std::string::npos){
		facebookTime++;
		facebookTimeInMinutes=facebookTime/60;
	}else
	
	if((titleBar.find("9GAG")!= std::string::npos) || (titleBar.find("KWEJK.pl")!= std::string::npos) || (titleBar.find("OLX")!= std::string::npos)){
		rubbishTime++;
		rubbishTimeInMinutes=rubbishTime/60;
	}else

	if((titleBar.find("Udemy")!= std::string::npos) || (titleBar.find("IntelliJ")!= std::string::npos) || (titleBar.find("Eclipse")!= std::string::npos)|| (titleBar.find("Notepad++")!= std::string::npos)|| (titleBar.find("PowerShell")!= std::string::npos)|| (titleBar.find("cmd.exe")!= std::string::npos)){
		veryGoodJobTime++;
		veryGoodJobTimeInMinutes=veryGoodJobTime/60;
	}else
	
	if(titleBar.find("Outlook")!= std::string::npos){
		outlookTime++;
		outlookTimeInMinutes=outlookTime/60;
	}else
	
	if(titleBar.find("YouTube")!= std::string::npos){
		youtubeTime++;
		youtubeTimeInMinutes=youtubeTime/60;
	}else
	
	if(titleBar.find("ekran blokady systemu Windows")!= std::string::npos){
		afkTime++;
		afkTimeInMinutes=afkTime/60;
	}
	else{
		okTime++;
		okTimeInMinutes=okTime/60;
	}
	
	std::cout<<"Very good time:		"<<veryGoodJobTimeInMinutes<<" minutes"<<std::endl;	
	std::cout<<"OK time: 		"<<okTimeInMinutes<<" minutes"<<std::endl;	
	std::cout<<"Outlook: 		"<<outlookTimeInMinutes<<" minutes"<<std::endl;
	std::cout<<"Facebook:		"<<facebookTimeInMinutes<<" minutes"<<std::endl;
	std::cout<<"YouTube: 		"<<youtubeTimeInMinutes<<" minutes"<<std::endl;
	std::cout<<"Wykop: 			"<<wykopTimeInMinutes<<" minutes"<<std::endl;
	std::cout<<"Rubbish: 		"<<rubbishTimeInMinutes<<" minutes"<<std::endl;
	std::cout<<"AFK: 			"<<afkTimeInMinutes<<" minutes"<<std::endl;

   sleep(1);

	}

	return 0;
}

string GetActiveWindowTitle()
{
	 char wnd_title[256];
	 HWND hwnd=GetForegroundWindow(); // get handle of currently active window
	 GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
	 return wnd_title;
}

