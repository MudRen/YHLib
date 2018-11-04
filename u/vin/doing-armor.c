// SN:jDbChk3ZYP<8=KFM
// ITEM Made by player(΢��:doing) /data/item/d/doing-armor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)     Fri Mar  2 15:57:34 2001
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
        set_name(HIG "������������" NOR, ({ "armor" }));
        set_weight(9000);
        set("item_make", 1);
        set("unit", "��");
        set("long", HIG "������Ů洲�������֮ʯ�ͱ���������Ϊ���ϴ��ƶ��ɵı��ף��������\n"
                    "����������������ͨ�����Եֵ�����һ�й�����Ȼ���˲���������������\n"
                    "�������������������\n" NOR);
        set("value", 1);
        set("point", 152);
        set("material", "magic stone");
        set("wear_msg", HIM "$N" HIM "չ��$n" HIM "��ֻ���̲���ת���⻪���䣬���������������ܡ�\n" NOR);
        set("remove_msg", HIG "$N" HIG "������$n" HIG "��ֻ��$n" HIG "����һƬ��ʯ��\n" NOR);
        if (! check_clone()) return;
        restore();
        set("armor_prop/armor", apply_armor());
        set("armor_prop/parry", apply_armor() / 15 + 1);

        setup();
}

mixed valid_damage(object ob, object me, int damage)
{
        if (wiz_level(me) > 0)
                return ([ "damage" : -damage,
                          "msg" : HIM "ֻ��" + name() + HIM "�⻪���䣬��������ɫ�ʣ�ѣ�˶�Ŀ��\n" NOR ]);
}

int wear()
{
        object owner;

        if (objectp(owner = environment()) &&
            playerp(owner))
        {
                if (wiz_level(owner) < 1)
                {
                        message_vision(HIM "$N" HIM "չ��$n"
                                       HIM "���������ϣ�ֻ��һ�����������ű���һ��\n"
                                       "�����ĵ�⻮����$N"
                                       HIM "��ʱ���������ʱ���ճɷɻҡ�\n" NOR,
                                       owner, this_object());
                        owner->set_temp("die_reason", "����������ճ��˷ɻ�");
                        owner->die();
                        return -1;
                }
        }

        return ::wear();
}

string long() { return query("long") + item_long(); }
