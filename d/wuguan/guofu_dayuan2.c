inherit ROOM;

void create()
{
        set("short", "������Ժ");
        set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��
ǿ����Ժ����ǳ��֣��Һ��ģ��㿴����ʱ�п��Ŷ�����
����ˮ���˴ҴҶ�������������̨�׾��ǹ����Ĵ�����
LONG);
        set("no_fight", 1);
        set("exits", ([
                "south" : __DIR__"guofu_dayuan",
                "north" : __DIR__"guofu_dating",
        ]));
        set("objects", ([
           	__DIR__"npc/yelvqi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
