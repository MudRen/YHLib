inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǻ�ɽ���£���ȻԶ���سǣ�ȴû��ʲ��ɽ���ݿ��ڸ�����û��
������һ��С��ׯ�������������˼Ҳ��࣬�����ǹ����ճ������������
Ϣ����������������С���ӣ������ϻ�ɽ��ɽ·�ˡ������м��Ʒ��ӡ�
LONG );

        set("exits", ([
                "east"      :__DIR__"nwroad1",
                "north"     : __DIR__"shack",
                "northwest" : "/d/heimuya/road6",
        ]));
        set("objects", ([
                __DIR__"npc/kid": 2,
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "village");

        setup();
        replace_program(ROOM);
}

