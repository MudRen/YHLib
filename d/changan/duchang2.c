//Room: duchang.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
������������СС�Ķ�����ֻҪ��˵�����Ķľߣ�����
���С��������������������ľ�����Ů�ǳԳԵ�Ц����������
�Ĵ�ţ����������������������㼸���Ϳ���������������
����ص�������ǽ�Ϲ���һ������(paizi)��
LONG);
        set("exits", ([
                "south" : __DIR__"qixiang3",
        ]));
        set("item_desc", ([
                "sign": @TEXT
�����ӷ���:
bet <kind> <amount> <money> 

ֻ���������Ų���Ƿ��

kind:
    ͷ�� <tc>��������ÿ�ο���ǰȷ����      ��һӮ��ʮ��
    ˫�� <sd>����������ͬ����Ϊż����      ��һӮʮ��
    ���� <qx>������֮��Ϊ�ߣ�              ��һӮ��
    ɢ�� <sx>������֮��Ϊ�����壬�ţ�ʮһ����һӮ��
TEXT
        ]));

        set("objects", ([
                __DIR__"npc/zhuangjia" : 1,
        ]));

        set("no_fight", 1);
        setup();
}
void init()
{
        add_action("do_bet", "bet");
}

int do_bet(string arg)
{
        object me = this_player();
        object zj;
        
        if (! objectp(zj = present("zhuang jia", this_object())))
                return notify_fail("ׯ�Ҷ�û�У���Ҫ��˭�ģ�\n");

        if (! living(zj))
                return notify_fail("�㻹�ǵ�ׯ��������˵�ɣ�\n");

        return notify_fail("�Բ���ϵͳ���ԣ�ĿǰֹͣӪҵ��\n");


}

