inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ﴣ���Ÿ��ָ�����״�����ʯͷ���е����ˣ��е���
�����е����������߿�����������Ҳ�����Ƕ�������
���ģ�ǧ�˰�̬�������۾��������ˡ�
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "north" : __DIR__"xiaolu", 
                "south"  :__DIR__"shilin1",
        ]));
        set("objects", ([
                "/d/beijing/npc/youke" : 1,
        ]));
        setup();
        replace_program(ROOM);
}