inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������������һ��Сʯ�ݣ������Ǵ�������ģ�����
���и����¯���̵��أ����л���һ��ʯ�����������һЩ��
������õı�����
LONG);
        set("exits", ([
                "south" : __DIR__"xiaodao2",
        ]));
        set("no_clean_up", 0);
        set("objects", ([
               __DIR__"obj/blade" : 2,
        ]));
        setup();
}
