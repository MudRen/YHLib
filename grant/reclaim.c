// claim.c

inherit F_CLEAN_UP;

int filter(object ob);

int main(object me, string arg)
{
	object *ob;
        int i;
        int n;
        float mem;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

	if (arg == "-r")
	{
		write(sprintf("Total %d objects has been cleaned.\n",
			      reclaim_objects()));
		return 1;
	}

        //ob = filter_array(objects(), (: filter :));

        ob = objects();
	ob -= ({ find_object(MASTER_OB),
		 find_object(SIMUL_EFUN_OB),
		 find_object(LOGIN_OB),
		 find_object(USER_OB), });

        if (! (n = sizeof(ob)))
        {
                write("None of unlinked objects found.\n");
                return 1;
        }

        write(sprintf("Total filterd objects:%d\n", n));
        mem = 0;
        for (i = 0; i < n; i++)
        {
                if (arg == "show")write(sprintf("  %4-d. %O - %d\n", i + 1, ob[i], refs(ob[i]) - 1));
                mem += memory_info(ob[i]);
        }
        mem = (float)mem / (1024 * 1024);
        write("Total memory cost: " + mem + " M \n");

	return 1;
}

int filter(object ob)
{
        if (environment(ob))
                return 0;

        if (inherits(ROOM, ob))
                return 0;

        if (refs(ob) <= 2)
                return 1;

        return 0;
}

int help()
{
	write(@TEXT
ָ���ʽ: reclaim

�������еĶ��������Щ��Ӧ�����������ڴ��еĶ���
TEXT );
	return 1;
}
