inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���谵�ķ��䣬���˼��Ŵ�֮��ʲô��û�С����ڹ��߻�
�����㲻�ɵĴ���һ����Ƿ��
LONG);
        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits", ([
                "north" : __DIR__"dating",
        ]));

        setup();
        replace_program(ROOM);
}
