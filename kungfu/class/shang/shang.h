
int permit_recruit(object ob)
{
        if (ob->query("detach/商家堡") || ob->query("betrayer/商家堡"))
        {
                command("sneer");
                command("say 你吃里爬外，反复无常，叫我如何收你？");
                return 0;
        }

        if (ob->query("born_family") != "山东商家")
        {
                command("heng");
                command("say 我商家堡向来不收外人，给我走开。");
                return 0;
        }

        if (ob->query("family/family_name") &&
            ob->query("family/family_name") != "商家堡")
        {
                command("sneer");
                command("say 你既然已经离家拜师，又跑回来作甚？");
                return 0;
        }

        return 1;
}

