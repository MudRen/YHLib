// auctiond.c
// ����ϵͳ
// Written by jjgod for hell. 01/10/01.

#pragma optimize
#pragma save_binary

#include <ansi.h>

inherit F_DBASE;

int clean_up() { return 1; }

#define auction_info    my["auction_info"]
#define lot_percent     4 / 100

public  void   add_auction(object me, object ob, int money);
public  void   cancel_auction(object me);
public  string check_auction_info();
private void   message_auction(string msg);
private string check_auction(object ob);

void create()
{
        mapping my;
        
        seteuid(getuid());
        
        set("channel_id", "����ʦ[Auctioneer]");
        CHANNEL_D->do_channel(this_object(), "sys", "���������Ѿ�������");

        my = query_entire_dbase();
        auction_info = ([ ]);
        set_heart_beat(1);
}

void heart_beat()
{
        mapping my;
        string *id;
        int i, money;
        object me;
        object ob;
        object obj;

        my = query_entire_dbase();
        
        if (! mapp(auction_info) || ! sizeof(auction_info))
                return;

        id = keys(auction_info);
        
        for (i = 0; i < sizeof(id); i++)
        {
                if (! objectp(me = find_player(id[i])))
                {
                        map_delete(auction_info, id[i]);
                        continue;
                }
                if (! objectp(obj = auction_info[id[i]]["goods"]))
                {
                        map_delete(auction_info, id[i]);
                        continue;
                }
                if (stringp(auction_info[id[i]]["now"]) &&
                    ! objectp(ob = find_player(auction_info[id[i]]["now"])))
                {
                        map_delete(auction_info[id[i]], "now");
                }

                if (time() - auction_info[id[i]]["time"] >= 10)
                {
                        auction_info[id[i]]["state"] += 1;
                        auction_info[id[i]]["time"] = time();
                        message_auction(sprintf("%s(%s)��%s��%s��%s�Ρ�",
                                                me->name(), id[i],
                                                filter_color(obj->short()),
                                                MONEY_D->money_str(auction_info[id[i]]["value"]),
                                                chinese_number(auction_info[id[i]]["state"])));
                        if (auction_info[id[i]]["state"] >= 3)
                        {
                                if (! objectp(ob))
                                {
                                        message_auction(sprintf("%s(%s)��%s���˾��ۣ�ȡ��������",
                                                                me->name(), id[i],
                                                                filter_color(obj->short())));
                                        map_delete(auction_info, id[i]);
                                        continue;
                                }
                                else
                                {
                                        money = auction_info[id[i]]["value"];
                                        message_auction(sprintf("%s(%s)��%s��%s�ɽ��ˡ�",
                                                                me->name(), id[i],
                                                                filter_color(obj->short()),
                                                                ob->name()));

                                        switch (MONEY_D->player_pay(ob, money))
                                        {
                                        case 0:
                                        case 2:
                                                tell_object(me, "����" + ob->name() + "������Ǯ"
                                                                "��ֻ�����ա�\n");
                                                tell_object(ob, "�����㸶����Ǯ��ֻ�����ա�\n");
                                                map_delete(auction_info, id[i]);
                                                continue;
                                        default:
                                                switch (MONEY_D->player_pay(me, money * lot_percent))
                                                {
                                                case 0:
                                                case 2:
                                                        tell_object(ob, "����" + me->name() + "������Ӷ��"
                                                                        "��ֻ�����ա�\n");
                                                        tell_object(me, "�����㸶����Ӷ��ֻ�����ա�\n");
                                                        map_delete(auction_info, id[i]);
                                                        continue;
                                                default:
                                                        // �������
                                                        tell_object(ob, "���յ���" + me->name() + "������" +
                                                                        obj->short() + "��\n");
                                                        tell_object(me, "���" + obj->short() + "���˴���"
                                                                        "��" + ob->name() + "��\n");
                                                        MONEY_D->pay_player(me, money);
                                                        map_delete(auction_info, id[i]);
                                                        obj->move(ob);
                                                        continue;
                                                }
                                        }
                                }
                        }
                }
        }
}

// ���һ������Ʒ
public void add_auction(object me, object ob, int money)
{
        mapping my;
        string id;
        string msg;

        my = query_entire_dbase();
        id = me->query("id");

        if (mapp(auction_info[id]))
        {
                tell_object(me, "������������Ķ�������������µ�����Ʒ"
                                "��\n");
                return;
        }
        if (stringp(msg = check_auction(ob)))
        {
                tell_object(me, msg);
                return;
        }
        if (! me->can_afford(money * lot_percent))
        {
                tell_object(me, "�㸶����Ӷ��ѽ��\n");
                return;
        }
        
        auction_info[id] = ([ "goods" : ob,
                              "time"  : time(),
                              "value" : money,
                              "lot"   : money * lot_percent,
                              "state" : 1, ]);
        tell_object(me, "�㿪ʼ����" + ob->short() + NOR "��Ŀǰ" + 
                        (strlen(msg = MONEY_D->money_str(money * lot_percent)) ?
                        "����Ҫ����" + msg : "����Ҫ����") + "Ӷ��\n");
        message_auction(sprintf("%s(%s)����%s��%s��һ�Ρ�", me->name(),
                                id, filter_color(ob->short()),
                                MONEY_D->money_str(money), ));
        return;
}

// ���������Ʒ
private string check_auction(object ob)
{
        string msg;

        if (! ob->query("value") && ! ob->query("base_value"))
                return "��������ɲ�ֵǮ�ġ�\n";

        if (ob->query("no_sell") || ob->query("no_drop"))
        {
                if (stringp(msg = ob->query("no_sell")))
                        return msg;
                return "��������ɲ������ˡ�\n";
        }

        if (ob->is_character())
                return "����Ҳ����������\n";

        if (ob->query("money_id"))
                return "��û�ù�Ǯ����\n";

        if (ob->query("food_supply"))
                return "�Եĺȵĵ�����ȥ�����ˡ�\n";
}

// ȡ��������Ʒ
public void cancel_auction(object me)
{
        mapping my;
        string id;
        string name;
        object ob;

        id = me->query("id");
        my = query_entire_dbase();

        if (! mapp(auction_info[id]))
        {
                tell_object(me, "��û���������κζ�����\n");
                return;
        }

        if (objectp(ob = auction_info[id]["goods"]))
                name = filter_color(ob->short());
        else name = "����Ʒ";

        tell_object(me, "��ȡ����������\n");        
        message_auction(sprintf("%s(%s)ȡ��������%s��%s��", me->name(), id,
                                gender_pronoun(me->query("gender")), name, ));
        map_delete(auction_info, id);
        return;
}

// �鿴������Ʒ
public string check_auction_info()
{
        mapping my;
        string msg, name;
        string *id;
        object ob;
        int i;

        my = query_entire_dbase();
        
        if (! mapp(auction_info) || ! sizeof(auction_info))
                msg = "Ŀǰû���κ�������������Ʒ��\n";

        else
        {
                msg = "Ŀǰ������������Ʒ��������Щ��\n";
                msg += HIC "��" HIY "����ҩ���������������������Ʒ������������������"
                       "�����������ߩ��������������۸񩤩���������" HIC "��\n" NOR;
                
                id = keys(auction_info);
                for (i = 0; i < sizeof(id); i++)
                {
                        if (! find_player(id[i]))
                        {
                                map_delete(auction_info, id[i]);
                                continue;
                        }
                        if (! objectp(ob = auction_info[id[i]]["goods"]))
                        {
                                map_delete(auction_info, id[i]);
                                continue;
                        }
                        
                        if (! stringp(auction_info[id[i]]["now"]) || 
                            ! objectp(find_player(auction_info[id[i]]["now"])))
                                name = "��";
                        else name = find_player(auction_info[id[i]]["now"])->name() +
                                    "(" + find_player(auction_info[id[i]]["now"])->query("id") +
                                    ")";

                        msg += sprintf(HIC "  %-20s %-30s %-20s %-20s\n" NOR,
                                       find_player(id[i])->name() + "(" +
                                       find_player(id[i])->query("id") + ")",
                                       filter_color(ob->short()),
                                       name, 
                                       MONEY_D->money_str(auction_info[id[i]]["value"]));
                }
                msg += HIC "��" HIY "����������������������������������������������������"
                       "��������������������������������������" HIC "��\n" NOR;
                msg += sprintf("Ŀǰ����%s������Ʒ��\n", chinese_number(sizeof(auction_info)));
                if (! sizeof(auction_info)) msg = "Ŀǰû���κ�������������Ʒ��\n";
        }
        return msg;
}

// ���뾺��
public void join_auction(object me, string name, int money)
{
        mapping my;
        object ob;
        object obj;

        my = query_entire_dbase();

        if (! mapp(auction_info[name]))
        {
                tell_object(me, "�����û��������ʲô������\n");
                return;
        }
        if (! objectp(ob = find_player(name)))
        {
                tell_object(me, "������Ѿ���������Ү��\n");
                map_delete(auction_info, name);
                return;
        }
        if (! objectp(obj = auction_info[name]["goods"]))
        {
                tell_object(me, "����������Ѿ�û�����������Ү��\n");
                map_delete(auction_info, name);
                return;
        }
        if (money <= auction_info[name]["value"])
        {
                tell_object(me, "������˼ҿ��²���Ҫ��\n");
                return;
        }
        if (stringp(auction_info[name]["now"]) &&
            auction_info[name]["now"] == me->query("id"))
        {
                tell_object(me, "�����ϴγ��۵ľ�����ɡ�\n");
                return;
        }

        message_auction(sprintf("%s(%s)����%s(%s)��%s��%s��һ�Ρ�",
                                me->name(), me->query("id"), ob->name(),
                                name, filter_color(obj->short()), 
                                MONEY_D->money_str(money)));
        auction_info[name]["now"] = me->query("id");
        auction_info[name]["value"] = money;
        auction_info[name]["time"] = time();
        auction_info[name]["lot"] = money * lot_percent;

        return;
}

// ����������Ϣ
private void message_auction(string msg)
{
        CHANNEL_D->do_channel(this_object(), "bill", msg);
}
