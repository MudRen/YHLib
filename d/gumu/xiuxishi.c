
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�ܴ�ķ��䣬���߷ǳ��谵������û��ʲô��Ķ�
����ֻ���м����һ����ʰ����������Ĵ󴲣����ϵı���Ҳ
�����������࣬���ž�������˯����
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"xiaowu1",
        ]));

        set("sleep_room",1);
        set("no_fight",1);
        set("no_steal",1);

        setup();
        replace_program(ROOM);
}
