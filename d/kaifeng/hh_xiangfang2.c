inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
�����Ǻ컨���ܶ��ں����Ե�һ���᷿���ǹ����컨���
��������ס�ġ��᷿������ż��Ŵ󴲣��������ӡ����й���
��ͣ�ʹ�˸���˯�⡣
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"hh_zoulang7",
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
