#include <weapon.h>
#include <ansi.h>

#define RAGE "「" HIR "某人克星" NOR "」"
#define RAGEC "「" HIR "某人克星" NOR

string look_sword();
void remove_effect(object me, int amount);

inherit BLADE;

void create()
{
        set_name(HIY "神聖屠刀" NOR, ({ "blade" }) );
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("no_sell", 1);
                set("long", (: look_sword :));
                set("value", 2000000);
                set("material", "???");
                set("stable", 100);
        }
        init_blade(500);
        setup();
}

void init()
{
        add_action("do_cast", "cast");
        add_action("do_kill1", "kill1");
}

string look_sword()
{
        return HIY
        "\n"
        "神聖屠刀+5：「" HIR "某人克星" HIY "」\n\n"
        "很明显，素还真铸造把刀的意图就是为了屠杀某人。\n" NOR
        "數據資料：\n"
        "傷害力：" WHT "1d10+5，對某人時獲得+10改善\n" NOR
        "零級命中值：" WHT "獲得+7改善\n" NOR
        "傷害類型：" WHT "揮砍\n" NOR
        "抗力加值：\n" WHT
        "  +100%魔法抗力\n" NOR
        "特殊功能：\n" WHT
        "  每天施展一次某人客星\n"
        "重量：" WHT "10\n" NOR
        "使用速度：" WHT "1\n" NOR
        "武器特長類別：" WHT "弯刀\n" NOR
        "種類：" WHT "單手持用\n" NOR
        "無法使用的職業：\n" WHT
        "  德魯伊\n"
        "  牧師\n"
        "  法師\n" NOR
        "唯一能使用的人物：\n" WHT
        "  混亂陣營的人物\n" NOR;
}

int do_cast(string arg)
{
        object me = this_player(), *obs;
        int n, i, flag, damage;

        if (! arg || arg == "")
                return notify_fail("你要施展什麽法術？\n");

        if (arg != "kill")
                return notify_fail("你無法施展此類法術。\n");

        if (arg == "kill")
        {
                me->clean_up_enemy();
                obs = me->query_enemy();

                if (! me->is_fighting())
                        return notify_fail("你只有在戰鬥中才能施展"
                                           RAGE "。\n");

                if (me->is_busy())
                        return notify_fail("你現在正在忙，沒有時間"
                                           "施法" RAGE "。\n");

                message_vision(HIW "\n$N" HIW "施法" RAGEC + HIW "」"
                               "，高聲念誦道：比迪姆·亞特蒙·泰里"
                               "阿普·埃控。\n\n" NOR, me);

                for (flag = 0, i = 0; i < sizeof(obs); i++)
                {
                        if (random(10) > 1)
                        {
                                tell_object(obs[i], HIR "你只見眼前光芒"
                                                    "一閃，霎時間無數光"
                                                    "線便如鋼針般刺入體"
                                                    "内，幾欲窒息。\n" NOR);

                                damage = 10000 + random(3000);

                                obs[i]->delete("env/immortal");
                                obs[i]->receive_wound("qi", damage);
                                obs[i]->receive_wound("jing", damage / 2, me);
                                obs[i]->start_busy(60);

                                message("vision", HIY + obs[i]->name() +
                                                  HIY "只見眼前光芒一閃"
                                                  "，霎時間無數光線便如"
                                                  "鋼針般刺入體内，幾欲"
                                                  "窒息。\n\n" NOR,
                                                  environment(me),
                                                  ({ obs[i] }));
                                flag = 1;
                        } else
                        {
                                tell_object(obs[i], HIC "你法術豁免率檢定"
                                                    "成功，避開了" RAGEC +
                                                    HIC "」的攻擊。\n" NOR);
                        }
                }
                if (! flag) 
                        message_vision(HIC "然而沒有任何人受到$N" RAGEC +
                                       HIC "」的影响。\n" NOR, me, 0, obs);
                return 1;
        }
}


int do_kill1(string str)
{
      int max;
      object me;

      if (! geteuid())
            seteuid (getuid());

      if (! str)
            me = this_player();

      else
            me = find_player(str);

      if (! me)
            return notify_fail ("没有这个玩家。\n");

      me->delete("env/immortal");
      me->die();
      return 1;
}

