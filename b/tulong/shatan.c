inherit ROOM;

void create()
{
        set("short", "ɳ̲");
        set("long", @LONG
һƬ���ɫ��ɳ̲���ޱ��޼ʵĴ󺣾�����ǰ�ˡ�������
�ĺ�ˮ����ӿ���Ľ�׵��˻�������Ʈ������ı���ãã��
����û��һ�㷫Ӱ����ĿԶ�������콻�紦����һƬ���ֲ�
�������Ǻ����������졣�������������е���ζ������΢΢��
�Ų��ˡ�
LONG);
        set("exits", ([
                "west" : __DIR__"haian",
        ]));

        set("objects", ([
                __DIR__"npc/liuyun" : 1,
        ]));

        set("outdoors", "tulong");
        setup();
}
