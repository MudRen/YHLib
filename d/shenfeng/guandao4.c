inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ�������߳�����Сɽ·����Ȼ����ȴ�ǹ�һ����
ͨ�С�С·˳��ɽ�н�Ϊƽ̹�ش�����������չ��
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
		"west" : __DIR__"xingxing1",
		"east" : __DIR__"guandao3",
	]));

	setup();
	replace_program(ROOM);
}
