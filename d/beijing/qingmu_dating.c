#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������˽�����ԭ���������������������ػ���ľ�õĴ������ڣ�ֻ
��һ�Ű����Ϲ����������ƣ��м�һ��д�š���������֮λ�������һ��д��
��������ƽ����֣֮λ����������һ���ľ (baimu)��������������ȫ��Ѫ�֡�
������һ������(duilian)��
LONG );
        set("valid_startroom", 1);
        set("exits", ([
        "north" : __DIR__"qingmu_fang1",
        ]));
        set("item_desc", ([
"baimu" : 
HIR "\n  ֻ����ľ��д����������У��ظ����������˵�ͬ��������\n"
"����԰���£�ԼΪ�ֵܣ��պ�����������Ϊһ�ҡ�����Ϊ����\n"
"�ݵ�Ϊĸ, ��Ϊ�֣���Ϊ��ã��������ģ�һѩǰ�ܣ�˳��\n"
"�е����ָ��������ѪΪ�ˣ�����������\n" NOR,
"duilian":
HIC "\n����߸ԣ�һ��Ϫɽǧ����\n" NOR +
HIG "�ų��󺣣����Ӻ�ˮ������\n" NOR,
        ]));
        set("objects", ([
                CLASS_D("yunlong") + "/chen" : 1
        ]));
        setup();
        "/clone/board/tiandihui_b"->foo();

       replace_program(ROOM);
}
