inherit ROOM;

void create()
{
	set("short", "��Ĺ�ڲ�");
	set("long", @LONG
��������Ĺ��һ�ƣ���Ȼ��ǰһ�ڣ�������һ����ӣ���
��ں����ģ��ƺ��������κζ�����
LONG);
	set("exits", ([
		"south" : __DIR__"sec1",
		"out" : __DIR__"luan2",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
