inherit ROOM;

void create()
{
	set("short", "���ķ�ɽׯ�㳡��");
	set("long", @LONG
������Ĵ������ţ����˽�����һ����ΰ��ɽׯӳ�����������ԭ
��������Ǵ�˵�е��ķ�ɽׯ����ֻ��������ɽׯ��������һƬ�ķ統�С�
�㲻�����˸�����������Ŵ�����һ���������ߵ����������š���
��ɽׯ���ĸ����ֵĴ��졣����Կ���ɽׯ�����������ǰ�档
LONG
	);
	set("exits", ([ 
           	"enter" : __DIR__"room",
           	"east" : __DIR__"eroom",
           	"out" : __DIR__"men",
           	"west" : __DIR__"wroom",
	]));
	set("objects", ([ 
		"/u/wfoxd/huyuan.c" : 1,
	]));
	replace_program(ROOM);
}
