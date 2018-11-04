// ��ҵϵͳ�ܿس���
// edit by smallfish 2002.3.17
// Updated by Vin for heros.cn
// Updated by Jjgod.

#include <ansi.h>
#include <config.h>
#include <getconfig.h>

/*
���ļ�Ϊ��ҵϵͳ�е��̵����ɳ���
���ļ��ṩ�����ļ����ã�
/cmds/usr/shop.c                        ���̲�ѯ����ָ��
/inherit/char/waiter.c                  ��Ƴ���ӿ��ļ�
/inherit/room/shop.c                    ���̳���ӿ��ļ�

�����Լ���Ƶĳ�����·����/clone/shop
���̻�Ƽ̳��ļ���/inherit/char/waiter.c

���̼̳��ļ���/inherit/room/shop.c
���̻�Ʋ��� *.o ��ʽ���ļ��洢���洢�ļ�����ڣ�/data/shop
������Ҫ������
string owner:           ����ID
int shop_type��         ����״̬(0 ��ʾ�ر�)
mapping vendor_goods:           ����۸�keys Ϊ����� base_name
mapping vendor_goods_num:       ��������������keys Ϊ����� base_name
int all_vendor_goods:           ���л��������ܺ�
mapping invite:                 ������ۿۣ�keys Ϊ����� id
string *ban:                    �ڻ��б�keys Ϊ�ڻ� id
*/

public mapping *query_shop();                                           // ���ص����б�
public int is_inited();                                                 // ���ص����Ƿ�ȫ����ʼ��
private int check_owner(string arg);                                    // ���������˺͵��̻�������Ƿ���ͬ
public int change_owner(object me,string arg,string owner);             // �޸ĵ��̵���(�������˺͵��̻������)
public int is_owner(string owner);                                      // �鿴��� owner �Ƿ���̵���
public int close_all(object me);                                        // �ر����е���
public int close_shop(object me,string arg);                            // �ر�ָ������
public int open_all(object me);                                         // �������е���
public int open_shop(object me,string arg);                             // ����ָ������
public int reset_all(object me);                                        // ��ʼ�����е���
public int reset_shop(object me,string arg);                            // ��ʼ��ָ������
public int list_shop(object me);                                        // ��ѯ����(�� listshop ָ�����)
public string do_modify(object obj, object me, string arg);             // �޸ĵ��̻�Ƶ�����
public string do_stock(object ob, object me, string arg);               // ��۲����ۻ���
public string do_unstock(object ob, object me, string arg);             // ȡ�»���
public string do_list(object ob, object me, string arg);                // ��ѯ����
public int do_buy(object obj, object me, string arg);                   // �������
private int player_pay(object who, object target, int amount);          // ���������ҵ�����Լ�˰��
public string do_jiezhang(object ob, object me);                        // ����(�������˲�����ʱ��ĵ�������)
public string list_invite(object ob, object me);                        // ��ѯ����б�
public string do_invite(object ob, object me, string arg);              // ����|ȡ�� ���
public string list_ban(object ob, object me);                           // ��ѯ�ڻ��б�
public string do_ban(object ob, object me, string arg);                 // ����|ȡ�� �ڻ�
private void destruct_it(object ob);                                    

string *special_props = ({ "short", "long" });

static mapping *all_shop = ({
        ([
                "id":             "����",
                "name":           "ͨ���",
                "start_room":     "yangzhou_shop",
                "type":           "shop",
                "price":          800,
        ]),
        ([
                "id":             "����",
                "name":           "�ٱ�ի",
                "start_room":     "changan_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "����",
                "name":           "��徸�",
                "start_room":     "luoyang_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "����",
                "name":           "�۱���",
                "start_room":     "beijing_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "����",
                "name":           "���԰",
                "start_room":     "dali_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "����",
                "name":           "��ׯ",
                "start_room":     "kaifeng_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "����",
                "name":           "������",
                "start_room":     "xiangyang_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "����",
                "name":           "������",
                "start_room":     "suzhou_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "����",
                "name":           "��ʸ�",
                "start_room":     "hangzhou_shop",
                "type":           "shop",
                "price":          500,
        ]),
        ([
                "id":             "��ɽ",
                "name":           "Ӣ��¥",
                "start_room":     "foshan_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "����",
                "name":           "ף�ھ�",
                "start_room":     "hengyang_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "����",
                "name":           "�ٺ�ի",
                "start_room":     "zhongzhou_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "����",
                "name":           "����ի",
                "start_room":     "fuzhou_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "�ɶ�",
                "name":           "����¥",
                "start_room":     "chengdu_shop",
                "type":           "shop",
                "price":          300,
        ]),
        ([
                "id":             "����",
                "name":           "�廪¥",
                "start_room":     "jingzhou_shop",
                "type":           "shop",
                "price":          300,
        ]),
});

public mapping *query_shop()
{
        return all_shop;
}

public int is_inited()
{
        int i, is_ok;
        object shop;

        is_ok = 1;

        for (i = 0; i < sizeof(all_shop); i++)
        {
                shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

                if (! shop || shop->query("shop_type"))
                {
                        is_ok = 0;
                        break;
                } else
                {
                        if ((shop->query("vendor_goods") &&
                             sizeof(shop->query("vendor_goods")) > 0) ||
                             shop->query("all_vendor_goods") ||
                             shop->query("owner") != "VOID_SHOP")
                        {
                                is_ok = 0;
                                break;
                        }
                }
        }
        return is_ok;
}

private int check_owner(string arg)
{
        int i, have_it;
        object the_shop;
        string shop_owner;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }

        // û���ҵ�ָ���ĵ���
        if (! have_it)
                return 0;

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (! the_shop)
                return 0;

        shop_owner = the_shop->query("owner");
        return 1;
}

public int change_owner(object me, string arg, string owner)
{
        int i, have_it;
        object the_shop;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }

        if (! have_it)
        {
                tell_object(me, "�Բ���" + arg + "���̲������ڡ�\n");
                return 1;
        }

        if (! check_owner(arg))
        {
                tell_object(me, "���棺" + arg + "�������˺͵��̻����"
                                "�������쳣������ϸ��顣\n");

                log_file("static/shop", sprintf("%s���������쳣��ʱ"
                         "�䣺%s��\n", arg, ctime(time())));
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (the_shop)
        {
                the_shop->set("owner", owner);
                the_shop->save();
                tell_object(me, arg + "���̵����޸���ϡ�\n");
        } else
        {
                tell_object(me, arg + "�����ļ������ڣ�����ϸ�鿴��\n");
                return 1;
        }

        return 1;
}

public int is_owner(string owner)
{
        int i;
        object shop;

        for (i = 0; i < sizeof(all_shop); i ++)
        {
                shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

                if (! objectp(shop))
                        return 0;

                if (shop->query("owner") == owner)
                        return 1;
        }
        return 0; 
}

public int close_all(object me)
{
        int i;

        for (i = 0; i < sizeof(all_shop); i++)
                close_shop(me, all_shop[i]["id"]);

        return 1;
}

// �رյ������޸ĵ��̵� shop_type Ϊ 0
public int close_shop(object me, string arg)
{
        int i, have_it;
        object the_shop;

        have_it = 0;

        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }

        if (! have_it)
        {
                tell_object(me, "�Բ���" + arg + "���̲������ڡ�\n");
                return 1;
        }

        if (! check_owner(arg))
        {
                tell_object(me, "���棺" + arg + "�������˺͵��̻��������"
                                "���쳣������ϸ��顣\n");
                log_file("static/shop",sprintf("%s���������쳣��ʱ�䣺"
                         "%s��\n", arg, ctime(time())));
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (the_shop)
        {
                the_shop->set("shop_type", 0);
                the_shop->save();
                tell_object(me, arg + "���̳ɹ��رա�\n");
        } else
        {
                tell_object(me, arg + "�����ļ������ڣ�����ϸ�鿴��\n");
                return 1;
        }
        return 1;
}

public int open_all(object me)
{
        int i;
        for (i = 0; i < sizeof(all_shop); i++)
                open_shop(me, all_shop[i]["id"]);
        return 1;
}

// ���ŵ������޸ĵ��̵� shop_type Ϊ 1
public int open_shop(object me, string arg)
{
        int i, have_it;
        object the_shop;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }
        if (! have_it)
        {
                tell_object(me, "�Բ���" + arg + "���̲������ڡ�\n");
                return 1;
        }

        if (! check_owner(arg))
        {
                tell_object(me,"���棺" + arg + "�������˺͵��̻�����������쳣������ϸ��飡\n");
                log_file("static/shop", sprintf("%s���������쳣��ʱ�䣺%s��\n", arg, ctime(time())));
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (the_shop)
        {
                the_shop->set("shop_type", 1);
                me->save();
                tell_object(me, arg + "���̳ɹ����ţ�\n");
        } else
        {
                tell_object(me, arg + "�����ļ������ڣ�����ϸ�鿴��\n");
                return 1;
        }
        return 1;
}

public int reset_all(object me)
{
        int i;
        for (i = 0; i < sizeof(all_shop); i++)
                reset_shop(me, all_shop[i]["id"]);
        return 1;
}

// ��ʼ�����̰�����
// �رյ���
// ���õ��̺ͻ�Ƶ�����Ϊ��ֵ
// �����ƵĻ����Լ���ƵĴ��
// �����ƵĹ���ͺڻ�
public int reset_shop(object me, string arg)
{
        int i, have_it;
        string *props, prop;
        object the_shop, the_waiter;
        mapping m;

        have_it = 0;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                if (all_shop[i]["id"] == arg)
                {
                        have_it = 1;
                        break;
                }
        }
        if (! have_it)
        {
                tell_object(me,"�Բ���" + arg + "���̲������ڡ�\n");
                return 1;
        }

        the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

        if (the_shop)
        {
                the_shop->set("shop_type", 0);
                the_shop->set("owner", "VOID_SHOP");
                the_shop->set("balance", 0);
                the_shop->delete("vendor_goods");
                the_shop->delete("vendor_goods_num");
                the_shop->delete("all_vendor_goods");
                the_shop->delete("invite");
                the_shop->delete("ban");

                the_shop->save();

                tell_object(me, arg + "���̳ɹ���ʼ����\n");
        } else
        {
                tell_object(me, arg + "�����ļ������ڣ�����ϸ�鿴��\n");
                return 1;
        }

        the_waiter = present("huo ji", the_shop);
        if (the_waiter)
        {
                if (arrayp(m = the_shop->query("waiter")) && sizeof(props = keys(m)))
                {
                        foreach (prop in props)
                        {
                                if (prop == "name")
                                        the_waiter->set_name("���̻��", ({ "huo ji", "huo", "ji" }));
                                if (prop == "long")
                                        the_waiter->set("long", "��������ҵ��̵Ļ�ơ�\n");
                                the_waiter->delete(prop);
                        }
                        the_shop->delete("waiter");
                }
                tell_object(me, arg + "��Ƴɹ���ʼ����\n");
        } else
        {
                tell_object(me, arg + "���̻�Ʋ����ڣ�����ϸ�鿴��\n");
                return 1;
        }
        return 1;
}

public int list_shop(object me)
{
        int i;
        string arg, na, msg;
        object ob, the_shop;

        msg = WHT "��ǰ" + LOCAL_MUD_NAME() + "�ĵ����б����£�\n" NOR;
        msg += HIC "��" HIY "������������������������������������������������������"
               "��������������" HIC "��\n" NOR;
        for (i = 0; i < sizeof(all_shop); i++)
        {
                arg = all_shop[i]["id"];

                if (! check_owner(arg))
                        continue;

                the_shop = load_object(SHOP_DIR + all_shop[i]["start_room"]);

                if (! the_shop)
                        continue;

                if (objectp(ob = find_player(the_shop->query("owner"))))
                        na = HIW + ob->query("name");
                else
                {
                        na = GRN "�������";
                }

                msg += sprintf(WHT " ���̣�" HIG "%s[" HIW "%s" HIG "]\t " NOR +
                               WHT "��Ӫ״̬��" HIG "%s" NOR +
                               WHT "  �������ˣ�" HIG "%s\n" NOR,
                               all_shop[i]["name"], 
                               arg, 
                               (the_shop->query("shop_type") &&
                               the_shop->query("owner") != "VOID_SHOP") ? HIG
                               "Ӫҵ��  " NOR : NOR + GRN "�ݲ�Ӫҵ" NOR,
                               the_shop->query("owner") == "VOID_SHOP" ? NOR +
                               GRN "������(ϵͳ)" NOR : NOR + na +
                               "(" + the_shop->query("owner") + ")" NOR,);
        }
        msg += HIC "��" HIY "������������������������������������������������������"
               "��������������" HIC "��\n" NOR;
        msg += WHT "�ܹ���" + chinese_number(sizeof(all_shop)) + "�ҵ��̡�\n" NOR;
        tell_object(me, msg);
        return 1;
}

public string do_modify(object obj, object me, string arg)
{
        string item, msg;
        mapping dbase;
        object room;
        
        room = environment(obj);

        if (! room->query("shop_type"))
                return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

        if (! arg || sscanf(arg,"%s %s", item, msg) != 2)
                return "�趨��ʽΪ��modify <��Ŀ> <����>\n";

        if (CHINESE_D->check_control(msg))
                return "���������п��Ʒ���\n";

        if (CHINESE_D->check_space(msg))
                return "�������費���ո�\n";

        if (CHINESE_D->check_return(msg))
                return "�������費���س�����\n";

        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$S$", BLINK);

        switch(item)
        {
        case "desc":
                if (CHINESE_D->check_length(msg) > 100)
                        return "�����趨������̫���ˡ�\n";

                obj->set("long", msg + NOR "\n");
                room->set("waiter/long", msg + NOR "\n");

                room->save();
                return WHT "��Ϊ���̻���趨����������\n" NOR;

        case "nickname" :
                if (CHINESE_D->check_length(msg) > 20)
                        return "�����趨������̫���ˡ�\n";

                obj->set("nickname", msg + NOR);
                room->set("waiter/nickname", msg + NOR);

                room->save();
                return WHT "��Ϊ���̻���趨���˴ºš�\n" NOR;

        case "title" :
                if (CHINESE_D->check_length(msg) > 20)
                        return "�����趨������̫���ˡ�\n";

                obj->set("title", msg + NOR);
                room->set("waiter/title", msg + NOR);

                room->save();
                return WHT "��Ϊ���̻���趨����ͷ�Ρ�\n" NOR;

        case "name" :
                if (CHINESE_D->check_length(msg) > 10)
                        return "�����趨������̫���ˡ�\n";

                if (! is_chinese(msg))
                        return "���̻�Ƶ�����ֻ�������ġ�\n";

                dbase = obj->query_entire_dbase();
                dbase["name"] = msg;
                
                room->set("waiter/name", msg);

                room->save();
                return WHT "��Ϊ���̻���趨�������֡�\n" NOR;
        }
        return "��Ҫ�޸�ʲô��\n";
}

public string do_stock(object ob, object me, string arg)
{
        object obj, goods, obj2;
        int value;
        mapping all_goods, all_goods_num;
        object room;
        
        room = environment(ob);
        
        if (! room->query("shop_type"))
                return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

        if (! arg || ! sscanf(arg, "%s value %d", arg, value) == 2) 
                return "ָ���ʽ��stock <����> value * (���� * ����ͭ������λ�ļ۸�)\n";

        if (! value)
                return "ָ���ʽ��stock <����> value * (���� * ����ͭ������λ�ļ۸�)\n";

        if (value > 10000000)
                return "���������һǧ���ƽ���ͱ���ô�ĺ��˰ɡ�\n";

        if (! (goods = present(arg, me)) || ! objectp(goods)) 
                return "�����ϲ�û��������ﰡ��\n";

        if (goods->query("no_sell"))
                return "�������̫��ҡ�ˣ����Ǳ��ó���������\n";

        if (goods->is_character()) 
                return "�㲻�ܷ������\n";

        if (goods->query("money_id")) 
                return "���ǮҲ�������ۣ�\n";

        if (room->query("all_vendor_goods") >= 80) 
                return "������ϵĶ���̫���ˣ����ռ��ֻ����ٰڰɡ�\n";

        all_goods = room->query("vendor_goods");

        if (! all_goods)
                all_goods = ([ ]);
 
        all_goods_num = room->query("vendor_goods_num");
 
        if (! all_goods_num)
                all_goods_num = ([ ]);

        all_goods[base_name(goods)] = value;
        all_goods_num[base_name(goods)] += 1;

        room->set("vendor_goods", all_goods);
        room->set("vendor_goods_num", all_goods_num);
        room->add("all_vendor_goods", 1);

        message_vision(HIW "$N" HIW "����" HIG + goods->name(1) +
                       HIW "������" HIY + MONEY_D->price_str(value) +
                       HIW "�ļ۸�ʼ���ۡ�\n" NOR, me);
        room->save();
        if (goods->query_amount() && goods->query_amount() > 1) 
        {
                goods->set_amount((int)goods->query_amount() - 1);
                obj2 = new(base_name(goods));
                obj2->set_amount(1);
                destruct(obj2);
        }
        else destruct(goods);
        return "����ú��˻��\n";
}

public string do_unstock(object ob, object me, string arg)
{
        object obj, goods, room;
        int i, amount, value, have_it = 0;
        mapping all_goods, all_goods_num;
        string *goods_key, ob_file;

        room = environment(ob);
        if (! room->query("shop_type"))
                return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

        if (! arg)
                return "ָ���ʽ��unstock <����>\n";

        if (! room->query("all_vendor_goods")) 
                return "�����ڻ�û�а����κλ��\n";

        all_goods = room->query("vendor_goods");
        all_goods_num = room->query("vendor_goods_num");

        if (sizeof(all_inventory(me)) >= MAX_ITEM_CARRIED)
                return "�����ϵĶ���̫���ˣ�û���ӻ�����ȡ������\n";

        all_goods = room->query("vendor_goods");

        if (! all_goods)
                all_goods = ([ ]);

        all_goods_num = room->query("vendor_goods_num");

        if (! all_goods_num)
                all_goods_num = ([ ]);

        goods_key = keys(all_goods);

        if (arrayp(goods_key))
        {
                for (i = 0; i < sizeof(goods_key); i++) 
                {
                        if (goods_key[i]->id(arg)) 
                                ob_file = goods_key[i];
                        else

                        if (filter_color(goods_key[i]->name(1)) == arg) 
                                ob_file = goods_key[i];
                }
        }

        if (! ob_file)
                return "����" + environment(ob)->short() + "�Ļ�����"
                       "��û���������\n";

        goods = new(ob_file);

        room->add("all_vendor_goods", -1);
        all_goods_num[base_name(goods)] -= 1;

        if (all_goods_num[base_name(goods)] == 0)
        {
                map_delete(all_goods, base_name(goods));
                map_delete(all_goods_num, base_name(goods));
        }

        message_vision(HIW "$N" HIW "����" HIG + goods->name(1) +
                       HIW "���ӻ�����ȡ���������ˡ�\n" NOR, me);
   
        room->set("vendor_goods", all_goods);
        room->set("vendor_goods_num", all_goods_num);
        room->save();

        if (! goods->move(me))
        {
                goods->move(environment(me));
                tell_object(me, "�������Ѿ��ò����ˣ�ֻ�ð�" +
                                goods->name(1) + NOR "���ڵ��ϡ�\n");
        }
        return "��ȡ���˻��\n";
}

public string do_list(object ob, object me, string arg)
{
        mapping goods, goods_num;
        string *gks;
        object *obs, *inv, room;
        string msg;
        int i, have_vendor = 0;

        mapping price;
        mapping unit;
        mapping count;
        string  short_name;
        string  prefix;
        string  *dk;

        room = environment(ob);
        if (! room->query("shop_type"))
                return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

        if (room->query("ban") &&
            member_array(me->query("id"), room->query("ban")) != -1)
                return "������ҵ��̲��ܻ�ӭ������޷���������\n";

        if (! room->query("all_vendor_goods")) 
                return "����" + room->short() + "Ŀǰ��û"
                       "�г����κλ��\n";

        goods = room->query("vendor_goods");

        if (! goods)
                goods = ([]);

        goods_num = room->query("vendor_goods_num");

        if (! goods_num)
                goods_num = ([]);

        count   = ([]);
        unit    = ([]);
        price   = ([]);
       
        gks = keys(goods);
        for (i = 0; i < sizeof(gks); i++)
        {
                object gob;
                call_other(gks[i], "???");

                if (! objectp(find_object(gks[i])))
                {
                        log_file("user_vendor", sprintf("No found vendo"
                                 "r good:%s\n", gks[i]));
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
                count += ([ short_name : goods_num[gks[i]] ]);
        }

        msg = "�õ���Ŀǰ����������Ʒ��\n";
        msg += "-------------------------------------------------------\n";
        dk = sort_array(keys(unit), 1);

        for (i = 0; i < sizeof(dk); i++)
        {
                int p;
                p = price[dk[i]];
                msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i]))) +
                               "-s��ÿ%s%s" CYN "(�ֻ�%s)\n" NOR, 
                               dk[i], unit[dk[i]], MONEY_D->price_str(p),
                               chinese_number(count[dk[i]]) + unit[dk[i]]);
        }

        msg += "-------------------------------------------------------\n";

        if (me->query("id") == room->query("owner")) 
                msg += "�ܹ�" + chinese_number(room->query("all_vendor_goods")) +
                       "�����\n";

        if (room->query("invite/" + me->query("id")))
                msg += WHT "���Ǳ��������������л��������"
                       HIW + chinese_number(room->query("invite/" + me->query("id"))) +
                       HIW "��" NOR + WHT "���Żݡ�\n" NOR;

        return msg;
}       

public int do_buy(object obj, object me, string arg)
{
        mapping goods,goods_num;
        int amount;
        int value, val_factor;
        string ob_file, *goods_key;
        object *obs,ob, env;
        string my_id;
        int i;
        object room;

        room = environment(obj);
        if (! room->query("shop_type"))
        {
               tell_object(me, "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n");
               return 1;
        }

        if (room->query("ban") && member_array(me->query("id"), room->query("ban")) != -1)
        {

               tell_object(me, "������ҵ��̲��ܻ�ӭ������޷���������\n");
               return 1;
        }

        if(me->is_busy())
        {
                tell_object(me, "ʲô�¶��õ���æ����˵�ɣ�\n");
                return 1;
        }

        if (! arg)
        {
                tell_object(me, "��Ҫ��ʲô������\n");
                return 1;
        }

        if (sizeof(all_inventory(me)) >= MAX_ITEM_CARRIED)
        {
                tell_object(me, "�����ϵĶ���̫���ˣ��ȴ���һ���������ɡ�\n");
                return 1;
        }

        goods = room->query("vendor_goods");

        if (! goods)
                goods = ([ ]);

        goods_num = room->query("vendor_goods_num");

        if (!goods_num)
                goods_num = ([]);

        goods_key = keys(goods);

        if (arrayp(goods_key))
        {
                for (i = 0; i < sizeof(goods_key); i++) 
                {
                        if (goods_key[i]->id(arg)) 
                                ob_file = goods_key[i];
                        else

                        if (filter_color(goods_key[i]->name(1)) == arg) 
                                ob_file = goods_key[i];
                }
        }

        if (! ob_file)
        {
                tell_object(me, "�õ��̲�û�г����������\n");
                return 1;
        }

        value = goods[ob_file];

        // ����ǹ���������Ż�
        if (room->query("invite/" + me->query("id")))
                value = value * room->query("invite/" + me->query("id")) / 10;

        ob = new(ob_file);
        call_out("destruct_it", 0, ob);
 
        switch (player_pay(me, obj, value))
        {
        case 0:
                tell_object(me, CYN + obj->name(1) + NOR +
                                CYN "��Ц������⵰��һ�ߴ���ȥ��\n" NOR);
                return 1;

        case 2:
                tell_object(me, CYN + obj->name(1) + NOR +
                                CYN "��ü����������û����Ǯ������Ʊ�ҿ�"
                                "�Ҳ�����\n" NOR);
                return 1;

        default:
                if (ob->query_amount())
                {
                        message_vision("$N��$n����������" + ob->short() + "��\n",
                                        me, obj);
                } else
                {
                        message_vision("$N��$n����������һ" + ob->query("unit") + 
                                       ob->query("name") + "��\n", me, obj);
                }
 
                ob->move(me, 1);
                goods_num[ob_file] -= 1;

                if (goods_num[ob_file] == 0) 
                {
                        map_delete(goods, ob_file);
                        map_delete(goods_num, ob_file);
                }

                room->set("vendor_goods", goods);
                room->set("vendor_goods_num", goods_num);
                room->add("all_vendor_goods", -1);
        }
        me->start_busy(1);
        room->save();
        return 1;
}

private int player_pay(object who, object target, int amount)
{
        object t_ob, g_ob, s_ob, c_ob, owner;
        int tc, gc, sc, cc, left;
        int v;
        int pay_amount;

        seteuid(getuid());

        if (amount >= 100000 && t_ob = present("cash_money", who))
                tc = t_ob->query_amount();
        else
        {
                tc = 0;
                t_ob = 0;
        }

        if (g_ob = present("gold_money", who))
                gc = g_ob->query_amount();
        else
                gc = 0;

        if (s_ob = present("silver_money", who))
                sc = s_ob->query_amount();
        else
                sc = 0;

        if (c_ob = present("coin_money", who))
                cc = c_ob->query_amount();
        else
                cc = 0;
        
        v = cc + sc * 100 + gc * 10000;

        if (amount < 100000 && v < amount)
        {
                if (present("cash_money", who))
                        return 2;
                else
                        return 0;
        }

        v += tc * 100000;

        if (v < amount) 
                return 0;
        else {
                left = v - amount;
                if (tc)
                {
                        tc = left / 100000;
                        left %= 100000;
                }
                gc = left / 10000;
                left = left % 10000;
                sc = left / 100;
                cc = left % 100;

                if (t_ob && ! g_ob && gc)
                {
                        g_ob = new(GOLD_OB);
                        g_ob->move(who, 1);
                }

                if (t_ob)
                        t_ob->set_amount(tc);

                if (g_ob)
                        g_ob->set_amount(gc);
                else
                        sc += (gc * 100);

                if (s_ob)
                {
                        s_ob->set_amount(sc);
                } else
                if (sc)
                {
                        s_ob = new(SILVER_OB);
                        s_ob->set_amount(sc);
                        s_ob->move(who, 1);
                }

                if (c_ob)
                {
                        c_ob->set_amount(cc);
                } else
                if (cc)
                {
                        c_ob = new(COIN_OB);
                        c_ob->set_amount(cc);
                        c_ob->move(who, 1);
                }

                pay_amount = amount * 99 / 100;

                if (owner = find_player(environment(target)->query("owner")))
                {
                        owner->add("balance", pay_amount);

                        if (query_ip_number(owner) != query_ip_number(who))
                                owner->add("vendor_score", pay_amount / 10000);
                } else
                        environment(target)->add("balance", pay_amount);
                return 1;
        }
}

public string do_jiezhang(object ob, object me)
{
       int amount;
       object room;
        
       room = environment(ob);
       if (! room->query("shop_type"))
               return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

       amount = room->query("balance");

       if (amount < 1)
              return "�����ڵ�ʱ��û���κε����롣\n";

       me->add("balance", amount);
       me->add("vendor_score", amount / 10000);

       tell_object(me, HIY "��������ʱ����" + MONEY_D->price_str(amount) +
                       HIY "�����룬����ȫ��ת���������š�\n");
       room->set("balance", 0);
       room->save();
       return "������ϣ��뼴ʱ�˶���Ŀ��\n";
}

public string list_invite(object ob, object me)
{
        int i;
        string msg, *invite_key;
        mapping invite;
        object room;
        
        room = environment(ob);
        if (! room->query("shop_type"))
                return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

        invite = room->query("invite");

        if (! invite || sizeof(invite) < 1)
                return "����û���趨�κεĹ����\n";

        msg = HIC "��������Ĺ�������¼�λ��\n" NOR;
        msg += HIC "��" HIY "������������������������" HIC "��\n" NOR;
        invite_key = sort_array(keys(invite), 1);

        for (i = 0; i < sizeof(invite_key); i++)
        {
                msg += sprintf(CYN "%-20s  " WHT "%s��\n" NOR,
                               invite_key[i], chinese_number(invite[invite_key[i]]));
        }

        msg += HIC "��" HIY "������������������������" HIC "��\n" NOR;
        msg += HIC "�ܹ��� " HIY + sizeof(invite) + HIC " �������\n" NOR;
        return msg;
}

public string do_invite(object ob, object me, string arg)
{
        int num;
        object body, room;

        room = environment(ob);

        if (! room->query("shop_type"))
                return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

        if (! sscanf(arg, "%s %d", arg, num) == 2)
                return "ָ���ʽ��invite <id> <����>\n";

        if (num < 1 || num > 10)
                return "ָ���ʽ��invite <id> <����>\n";

        if (num == 10)
        {
                if (! room->query("invite/" + arg))
                        return CYN + ob->name(1) + NOR + CYN "����˵������"
                               "�壬�� " + arg + " �����Ͳ������ǵ�Ĺ������"
                               "\n" NOR;

                room->delete("invite/" + arg);
                room->save();
                return CYN + ob->name(1) + NOR + CYN "�����ʲ��û��˻�����"
                       "Ц�����ϰ壬�Ѿ�������ķԸ�ȡ���� " + arg + " �Ĺ�"
                       "���ʸ��ˡ�\n" NOR;
        }

        if (sizeof(room->query("invite")) >= 30)
                return "���Ѿ��趨����ʮ��������Ѳ��������Ȼ����ɡ�\n";

        room->set("invite/" + arg, num);
        room->save();

        return CYN + ob->name(1) + NOR + CYN "�����ʲ���д��˵�����ϰ壬��"
               "��������ķԸ��� " WHT + arg + CYN " ʵ��" + HIY + chinese_number(num) +
               "��" + NOR + CYN "�Żݡ�\n" NOR;
}

public string list_ban(object ob, object me)
{
        int i;
        string msg, *ban;
        object room;
        
        room = environment(ob);

        if (! room->query("shop_type"))
               return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";

        ban = room->query("ban");

        if (! ban || sizeof(ban) < 1)
        {
                msg = "����û���趨�κεĺڻ���\n";
                return msg;
        }
        msg = HIC "��������ĺڻ���������ң�\n" NOR;
        msg += HIC "��" HIY "������������������������" HIC "��\n" NOR;
        for (i = 0;i < sizeof(ban);i++)
        {
                msg += sprintf(CYN "  %s\n" NOR, ban[i]);
        }
        msg += HIC "��" HIY "������������������������" HIC "��\n" NOR;
        msg += HIC "�ܹ��� " HIY + sizeof(ban) + HIC " ���ڻ���\n" NOR;        
        return msg;
}

public string do_ban(object ob, object me, string arg)
{
        string the_id, type, *ban;
        object room;
        
        room = environment(ob);

        if (! room->query("shop_type"))
               return "�Բ��𣬸õ���Ŀǰ�Ѿ�����ʦ�رա�\n";
        
        ban = room->query("ban");

        if (! ban)
                ban = ({ });

        if (sscanf(arg, "%s %s", type, the_id) == 2 && type == "-")
        {
                if (member_array(the_id, ban) == -1)
                        return CYN + ob->name(1) + NOR + CYN "����˵������"
                               "�壬�� " + arg + " �����Ͳ������ǵ�ĺڻ�����"
                               "\n" NOR;

                ban -= ({ the_id });
                room->set("ban", ban);
                room->save();
                return CYN + ob->name(1) + NOR + CYN "�����ʲ����˻�������"
                       "��Ц�����ϰ壬�Ѿ�ȡ���� " + the_id + " �ڻ���ݡ�\n";
        }
        
        if (member_array(arg, ban) != -1)
                return CYN + ob->name(1) + NOR + CYN "��Ц�ŵ����ϰ壬����"
                       "���ˣ���" + arg + "���ѱ���Ϊ�ڻ�����\n" NOR;

        if (sizeof(ob->query("ban")) >= 30)
                return "���Ѿ��趨����ʮ���ڻ��������Ȼ���һЩ�ɡ�\n";

        ban += ({ arg });
        room->set("ban", ban);
        room->save();
        return CYN + ob->name(1) + NOR + CYN "�����ʲ���д��˵�����ϰ壬��"
               "��������ķԸ��� " WHT + arg + CYN " ��Ϊ�˺ڻ���\n";
}

private void destruct_it(object ob)
{
        if (! ob || environment(ob))
                return;

        destruct(ob);
}
