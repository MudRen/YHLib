#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�ֽ�ͨ�춴���ڶ��ڵ��ұ��Ͽ�����̬���죬һ�ɶ�ߵķ�����
�����·������鸡��ǰһ���������ɮȡ���Ĺ��£���һ��Ϊ��
���Ծ������С��÷�����������Ħ�ڡ���������������ɽ��·��С·
����������������
LONG);
        set("exits", ([
                "west" : __DIR__"shexudong",
                "east"  : __DIR__"feilaifeng",
        ]));

        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
