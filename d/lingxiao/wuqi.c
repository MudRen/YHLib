inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ǵĵ����̡��߽�����������壬���������
��Ҫ�䡣��ϸһ����ǽ�Ϲ����˴��СС������ɫɫ�ĵ�����һ
��������������ȫ����Ʒ��������ԯ���������˽�����������
�ڵ�ӭ��ǰ����
LONG );
        set("exits", ([
                "east" : __DIR__"iceroad2",
        ]));
        set("objects", ([
                "/d/luoyang/npc/smith": 1,
        ]));
        setup();
        replace_program(ROOM);
}

