inherit ROOM;

void create()
{
        set("short", "�͵��¥");
        set("long", @LONG
�����ǿ͵�Ķ�¥���Ŵ�һ���ſ���һЩ����������˯
�ĺ��������죬�Ŵ����գ����λ谵���㲻��Ҳ��˯ɽ��һ����
LONG);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([
                "eastdown" : __DIR__"kedian",
        ]));
        setup();
        
}

int valid_leave(object me, string dir)
{
        if (dir == "eastdown" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}
