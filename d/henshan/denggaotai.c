inherit ROOM;

void create()
{
        set("short", "�Ǹ�̨");
        set("long", @LONG
�����������ŵǸ���Զ�ĺ�ȥ������վ�����������壬
���������衣ң���潭��ȥ������ű���ʱ��ʱ�֡���Χ��ϼ��
���ޣ��ϸǣ�������廷����������ǧ��
LONG);
        set("exits", ([
               "northwest"  : __DIR__"nantian",
        ]));

        set("objects", ([
                __DIR__"npc/youke" : 4,
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

