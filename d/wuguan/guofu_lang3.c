inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�һֱͨ���Ժ���ϱ��������䳡��
LONG);
        set("no_fight", 1);
        set("exits", ([
               "north" : __DIR__"guofu_shilu-4",
               "south" : __DIR__"guofu_wuchang3",
        ]));
        setup();
        replace_program(ROOM);
}
