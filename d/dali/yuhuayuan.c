inherit ROOM;

void create()
{
        set("short", "����԰");
        set("long", @LONG
�����Ǵ�����ʹ�������԰�����ԵĻ��������涷�ޣ���
����һ��Сˮ�أ�ɽ����������Ȫˮ�ͻἯ�������ֻ�ɺ�
��ˮ��ץ�㣬һ���������˵����ӣ������ǻ��ȡ�
LONG);
        set("objects", ([
                "/clone/quarry/he": 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "north"  : __DIR__"hualang",
                "south"  : __DIR__"qiandian",
        ]));
        setup();
        replace_program(ROOM);
}
