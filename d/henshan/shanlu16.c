inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long",@LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�
�������ƣ��������ش�졣����ǰ��Զ�����ϸǷ��ˡ�
LONG);
	set("exits",([
	        "southdown" : __DIR__"shanlu15",
	        "northup" : __DIR__"zigai",
	]));
	
	set("outdoors", "henshan");    
          
	setup();
	replace_program(ROOM);
}  	
