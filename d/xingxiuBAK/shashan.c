inherit ROOM;

void create()
{
        set("short", "��ɳɽ");
        set("long", @LONG
����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ�������˵�
�������ʶ������˳�֮Ϊ��ɳɽ��ɳ�����ƺ��г������䶯��
LONG);
        set("outdoors", "xingxiu");
        set("exits", ([
                "west"      : __DIR__"yueerquan",
                "northeast" : __DIR__"silk3",
        ]));
        set("objects", ([
                "/clone/worm/tieguxie" : 1
        ]));
        setup();
        replace_program(ROOM);
}

