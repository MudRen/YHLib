inherit ROOM;

void create()
{
        set("short", "����ƺ");
        set("long", @LONG
ÿ���������ں�ɽ������������������ɽ����ӿ������
��ɽ����ǰɽ��к��ֱ�����ӷ�к��εΪ׳�ۣ������������
�������澰��
LONG);
        set("exits", ([ 
               "westdown"  : __DIR__"nantian",
               "eastup"    : __DIR__"shilinfeng",
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

