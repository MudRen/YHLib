inherit ROOM;

void create()
{
	set("short","�����");
	set("long",@LONG
����һ�����ң����ﴰ���������þ߿��������Ǵ���
һ������������Ǽ�ֵ���ơ�ƾ�������������ڵ���֮�п�
����ɽ����ַ壬������Σ������Ŀ�������
LONG);
	set("objects", ([
	   	__DIR__"npc/shouling" : 1,
	]));
	set("exits", ([
	    	"south" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

