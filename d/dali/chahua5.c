inherit ROOM;

void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����
վ�ڲ軨԰�У����ּ��使�����εĲ軨���㲻���࿴����
�ۡ�������һ��С�����������������������
LONG);
	set("objects", ([
	   	__DIR__"obj/chahua11": 1,
	   	__DIR__"obj/chahua12": 1,
	   	__DIR__"obj/chahua13": 1,
	   	__DIR__"npc/huanu": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"northwest"  : __DIR__"chahua3",
	    	"southwest"  : __DIR__"chahua4",
	]));
	setup();
	replace_program(ROOM);
}

