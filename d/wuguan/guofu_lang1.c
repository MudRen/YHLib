inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�ͨ�������䳡�����Ǽ������߹�����ʱ��
�˱�̧�����������������������赹�ġ�
LONG);
        set("no_fight", 1);
        set("exits", ([
               "west" : __DIR__"guofu_wuchang1",
               "east" : __DIR__"guofu_dayuan",
        ]));
        setup();
        replace_program(ROOM);
}
