#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIW "�����赨��" NOR, ({"shadan wan", "wan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "������������ҩ�����ƶ��ɵĵ�ҩ�������һ����Ķ�����ҩ��\n" NOR);
                set("base_unit", "��");
                set("base_value", 5000);
                set("base_weight", 70);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "tianqi"   : 3,
                                    "shadan"   : 3,
                                    "lanhua"   : 1,
                                    "honghua"  : 1,
                                    "wulingzhi": 1,
                                    "lurong"   : 1,
                                    "zzfen"    : 1,
                                    "yjhua"    : 1,
                                    "xuejie"   : 1,
                                    "shengdi"  : 1 ]),
                        "neili" : 200,
                        "jing"  : 40,
                        "time"  : 6,
                        "min_level" : 160,
                        "taohua-yaoli" : 160,
                ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/wuchang") < 80)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        if (me->query("neili") >= me->query("max_neili"))
        {
                write("����������������������������赨�衣\n");
                return 1;
        }

        me->set_temp("last_eat/wuchang", time());

        message_vision(HIW "$N" HIW "���������赨�裬������һ��������ɫ��ú���������\n" NOR, me);
        tell_object(me, HIC "��ֻ�����������棬�ƺ���ʹ�����������\n" NOR);

        my = me->query_entire_dbase();
        my["neili"] = my["max_neili"];

	me->start_busy(3);

        add_amount(-1);
        if (query_amount() < 1)
                destruct(this_object());

	return 1;
}
