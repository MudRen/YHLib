inherit ROOM;

void create()
{
	set("short","��ɽɽ·");
	set("long",@LONG
�˴������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£���ǰ��һ��
����Ա����϶������ڴ����򶫣�������ȥ����ˮ������ӿ
֮�����Ļ��Ӱ�������һ�����˵ĺ��졣��ǡ����壬��
����խ���ӹ��ϲ���������ֻ������������������������
����һ�ô����ϣ��ƿ���Ԯ������
LONG);
	set("objects", ([
	   	__DIR__"npc/lieren": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"northeast" : __DIR__"cangshanzhong",
	    	"west" : __DIR__"heshang",
	]));
	setup();
	replace_program(ROOM);
}

