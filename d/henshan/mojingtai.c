inherit ROOM;

void create()
{
        set("short", "ĥ��̨");
        set("long", @LONG
ĥ��̨λ���������£����ɽͤһ�����ڡ�̨ǰ���·ת��
̨�Թ��ɲԴ䣬�������ġ��ഫ�������ڻ����ڴ��������
���š�����̨��ɮ����������ĥ�����Ƿ����ڵ�һ����̨���
��������ĥ��̨֮�ġ��Ǻ�ɽ���ľ�֮һ��
LONG);
        set("exits", ([
                "southdown"  : __DIR__"shanlu8",
                "westup"     : __DIR__"shanlu7",
                "northup"    : __DIR__"shanlu6",
        ]));

        set("objects", ([
                __DIR__"npc/youke" : 2,
        ]));               
 
        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
