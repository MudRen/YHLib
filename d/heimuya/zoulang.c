inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǳɵµ��ڵ�һ��ľ�Ƶ����ȣ����������ǹ⻬����
�����ȱ�������һ����Ⱦ���㲻ʱ�ܹ����������ɵµ����Ů
�ڴ��߶���æµ����ͣ��
LONG);
        set("exits", ([
                "north"  : __DIR__"huoting",
                "south"  : __DIR__"chengdedian",
        ]));
        set("objects", ([
                __DIR__"npc/zish" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
