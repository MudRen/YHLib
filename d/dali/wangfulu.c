inherit ROOM;

void create()
{
	set("short","����·");
	set("long",@LONG
��������ǰ��������������ࡣ����������ڴ�Ĳ�ɫ
ʯ���������ɣ���������ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ
�׸��죬��ʳ�����޲�������ԭ��̫ѧ���ǵ�����֮��͸��
���š�������һ�����Ƹ�Ժ�������ϡ������������������
������ǰ��
LONG);
	set("objects", ([
	   	CLASS_D("duan") + "/fu": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"west" : __DIR__"paifang",
	    	"north" : __DIR__"wangfugate",
	]));
	setup();
	replace_program(ROOM);
}

