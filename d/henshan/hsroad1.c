inherit ROOM;

void create()
{
       set("short", "��·");	
       set("long", @LONG
������һ����������Ļ���·�ϣ�����������ɭɭ�����֡�
������ͨ�����ݣ����Ͼͽ�����ϵؽ��ˡ�
LONG );    
 
      set("outdoors", "henshan");  
   
      set("exits", ([
		"northdown" : "/d/wudang/wdroad4",	
                "southeast" : __DIR__"hsroad2",

	]));

	setup();
	replace_program(ROOM);
}
