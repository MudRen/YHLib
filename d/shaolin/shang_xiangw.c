inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
�������̼ұ����������һ���᷿���ǹ���Զ���Ŀ��˺���
�ҵ�������ס�ġ��᷿������ż��Ŵ󴲣��������ӡ����й���
��ͣ�ʹ�˸���˯�⡣
LONG);
	set("exits", ([
		"east"  : __DIR__"shang_houting",
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
