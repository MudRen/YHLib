inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������ׯ�ڴ�ű������صأ���������˱�����ʮ�˰�
����������ȫ�������Ա߹�����ʮ����������Ŀ���������ս
ѥ���һλؤ�������������Ŀ���񣬿��������
LONG);
        set("exits", ([
                "east"  : __DIR__"ma_lianwu1",
        ]));
        set("objects", ([
                "/d/gaibang/npc/5dai" : 1,
                "/d/gaibang/npc/obj/staff" : 3,
                "/clone/weapon/changjian" : 2,
                "/clone/weapon/gangdao" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
