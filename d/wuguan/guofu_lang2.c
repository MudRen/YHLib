inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�ͨ�����䳡�����������ģ��������֡�
LONG);
        set("no_fight", 1);
        set("exits", ([
               "east" : __DIR__"guofu_wuchang2",
               "west" : __DIR__"guofu_dayuan",
        ]));
        setup();
        replace_program(ROOM);
}
