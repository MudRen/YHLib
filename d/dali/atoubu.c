inherit ROOM;
void create()
{
	set("short","��ͷ��");
	set("long",@LONG
��ͷ�����������Ĳ��䣬�͸���������һ����Ҳ������
�ġ�����ɽ�����ܣ�����������ʽ�ɽ����������·������
ɥ������ɽ��������˵ȴ�Ǿ۱��裬ɽ��Ұ�������ζ��
LONG);
	set("objects", ([
	   	__DIR__"npc/lieren": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"north"      : __DIR__"lushui",
	    	"westup"     : __DIR__"gaolishan1",
	    	"southeast"  : __DIR__"yixibu",
	]));
	setup();
	replace_program(ROOM);
}

