
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˶�ɽ·��ͨ����ɽ�š���������һ��Ƭ���֡������¿�
������һ���ϴ�ĺ���
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southup"   : __DIR__"shulin12",
                "northdown" : __DIR__"taiyi1",
        ]));

        setup();
        replace_program(ROOM);
}
