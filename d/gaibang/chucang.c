inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ؤ��Ĵ����ң�����Կ���һ�������ŵ����ӡ���
Χ��������һЩ������װ������ʱ��һλؤ�������������Ŀ
���񣬿��������
LONG);
        set("exits", ([
                "west" : __DIR__"undertre",
        ]));
        set("objects", ([
                "/d/gaibang/npc/5dai" : 1,
                "/d/gaibang/npc/obj/staff" : 3,
                "/clone/weapon/gangdao" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
