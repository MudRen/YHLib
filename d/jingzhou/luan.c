inherit ROOM;

void create()
{
	set("short", "�ҷظ�");
	set("long", @LONG
������һ���ҷظڣ����������˹��˸ߵĳ��ݣ���˵����
�ֹ�����û�˸�����һ�����������ŵ��������ë����
LONG);

	set("exits", ([
		"westup" : __DIR__"xiaoshan",
		"east" : __DIR__"luan2",
	]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}
