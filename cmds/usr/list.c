#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping goods;
        string *gks;
        object *obs, obj, env, *inv;
        string msg;
        int i, have_vendor = 0;

        mapping price;
        mapping unit;
        string short_name;
        string prefix;
        string *dk;

        env = environment(me);

	if (! arg)
        {
                inv = all_inventory(env);

                if (! inv)
                        return notify_fail("���ﲢû���κ��ڰ�̯�����ˡ�\n");

                msg = HIC "���������С̯���У�"
                      HIY "\n����������������������������\n" NOR;
                for (i = 0; i < sizeof(inv); i++)
                {
                        if (userp(inv[i]) && inv[i]->query_temp("on_baitan"))
                        {
                                have_vendor = 1;
                                msg += WHT + inv[i]->name(1) + "���ӻ�̯(" +
                                       inv[i]->query("id") + ")\n";
                        }
                }
                if (! have_vendor) 
                        msg = WHT "Ŀǰ���ﲢû���κΰ�̯�����ˡ�\n" NOR;
                else
                        msg += HIY "����������������������������\n" NOR;
                write(msg);
                return 1;
        }

        if (! (obj = present(arg, env)) || ! userp(obj))
                return notify_fail("���ﲢû��������ˡ�\n");

        if (! obj->query("is_vendor"))
                return notify_fail(obj->name(1) + "���������ˡ�\n");

        if (! obj->query_temp("on_baitan"))
                return notify_fail(obj->name(1) + "Ŀǰ��û���ڰ�̯��\n");

        goods = obj->query("vendor_goods");

        if (! goods)
                return notify_fail(obj->name(1) + "Ŀǰ��û�ж����κλ��\n");

        gks = keys(goods);

        for (i = 0; i < sizeof(gks); i++)
        {
                if (! present(gks[i]->query("id"), obj))
                        map_delete(goods, gks[i]);
        }

        obj->set("vendor_goods", goods);
        goods = obj->query("vendor_goods");

        unit = ([]);
        price = ([]);

        gks = keys(goods);

        for (i = 0; i < sizeof(gks); i++)
        {
                object gob;
                call_other(gks[i], "???");

                if (! objectp(find_object(gks[i])))
                {
                        log_file("user_vendor", sprintf("No found vend"
                                 "or good:%s\n", gks[i]));
                        continue;
                }

                gob = find_object(gks[i]);
                short_name = gob->name(1) + "(" + gob->query("id") + ")";

                if (gob->query("base_unit"))
                        prefix = "base_";
                else
                        prefix = "";

                unit  += ([ short_name : gob->query(prefix + "unit") ]);
                price += ([ short_name : goods[gks[i]] ]);
        }

        msg = HIC + obj->name(1) + "Ŀǰ����������Ʒ��"
              HIY "\n��������������������������������������������������\n" NOR;
        dk = sort_array(keys(unit), 1);

        for (i = 0; i < sizeof(dk); i++)
        {
                int p;
                p = price[dk[i]];

                msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i]))) +
                               "-s��ÿ%s%s" CYN "\n" NOR, 
                               dk[i], unit[dk[i]], MONEY_D->price_str(p));
        }
        msg += HIY "��������������������������������������������������\n" NOR;
        write(msg);
        return 1;
}       

int help (object me)
{
        write(@HELP
ָ���ʽ: list <ID>
 
�г�һ������������ڳ��۵���Ʒ��
 
HELP);
        return 1;
}
