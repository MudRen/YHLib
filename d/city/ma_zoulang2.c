inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ׯ�ڵ�һ��ľ�Ƶ����ȣ����������ǹ⻬������
���ȱ�������һ����Ⱦ���㲻ʱ�ܹ���������ؤ��ĵ����ڴ�
�߶���æµ����ͣ�������Ǹ����䳡��
LONG);
        set("exits", ([
                "north"  : __DIR__"ma_lianwu1",
                "south"  : __DIR__"ma_zoulang1",
        ]));
        set("objects", ([
		"/d/gaibang/npc/2dai" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
