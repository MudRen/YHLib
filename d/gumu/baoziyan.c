
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ·������ɽ·��Խ��Խ�ա�ֻ����ͺͺ��ɽ·�����Ծ�
�ǹ�ʯ����������������Ԩ���첻���ס�ǰ����Զ����һ���
ʯ�����������ı����ҡ��ٿ����ۣ�����������������֣���
��һ�����˱��Ÿ����Ӱ㣬ϸ�ĺǻ������Ϻ�������һƬ���֡�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west"      : __DIR__"shulin8",
                "south"     : __DIR__"shulin9",
        ]));
        set("objects", ([
                CLASS_D("quanzhen") + "/chen" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
