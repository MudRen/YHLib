inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������������֮�¡��������а˸�ɽͷ�����������꣬
�����¾ͽ������������ĵ�һƬƽ���ϡ��������ţ��С�����
�����£���֪����֮�֮˵���ʡ�������֮�Ϊ��ɽ����
��֮һ��
LONG);
        set("exits", ([
                "southdown"  : __DIR__"shanjian",
                "eastup"     : __DIR__"shanlu10",
        ]));

        set("objects", ([
                __DIR__"npc/youke" : 4,
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

