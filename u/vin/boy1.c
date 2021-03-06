#include <ansi.h>
inherit NPC;

mixed ask_tanqin();
mixed ask_stop();

void create()
{
        set_name("琴才子", ({ "qin caizi", "qin", "caizi" }));
        set("long", "小童。\n");
        set("gender", "男性");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("combat_exp", 100000);

        set_skill("tanqin-jifa", 300);
        set_skill("qiuyue-lai", 300);
        set_skill("literate", 300);
        map_skill("tanqin-jifa", "qiuyue-lai");

        set("tattoo/face_long", "一台七弦琴");

        set("inquiry", ([
                "弹琴" : (: ask_tanqin :),
                "停止" : (: ask_stop :),
        ]));

        setup();

        carry_object("clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/henshan/yueqi/jiuxiaoqin"));
}

mixed ask_tanqin()
{
        object me;

        me = this_player();

        if (me->query("id") != "vinwf")
                return RANK_D->query_respect(me) + "与在下素不相"
                       "识，不知此言从何说起？";

        if (query("tanqin"))
                return "我现在正在弹琴，您听就是了。";

        command("nod");
        command("play qiuyue-lai");
        set("tanqin", 1);

        remove_call_out("tanqin");
        call_out("tanqin", 2, me);
        return 1;
}

mixed ask_stop()
{
        object me;

        me = this_player();

        if (! query("tanqin"))
                return "我现在没在弹琴啊。";

        if (me->query("id") != "vinwf")
                return RANK_D->query_respect(me) + "与在下素不相"
                       "识，不知此言从何说起？";

        command("nod");

        delete("tanqin");
        return 1;
}

void tanqin(object me)
{ 
        if (! query("tanqin"))
                return;

        command("play qiuyue-lai");

        remove_call_out("tanqin");
        call_out("tanqin", 2, me);
        return;
}
